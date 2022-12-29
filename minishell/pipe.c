/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:52:38 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/29 09:50:35 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parent_process(t_token token, int p_fd[], pid_t pid)
{
	if (token.redirect_out == STDOUT_FILENO)
	{
		if (dup2(p_fd[READ], STDIN_FILENO) < 0)
			print_error(ERR_DUP, NULL);
	}
	if (waitpid(pid, NULL, 0) == -1)
		print_error(ERR_WAITPID, "waitpid");
	close(p_fd[0]);
	close(p_fd[1]);
}

static void	child_process(char *cmd_path, t_token token, int p_fd[])
{
	if (token.redirect_out != STDOUT_FILENO)
	{
		if (dup2(token.redirect_out, STDOUT_FILENO) < 0)
			print_error(ERR_DUP, NULL);
	}
	else
	{
		if (dup2(p_fd[WRITE], STDOUT_FILENO) < 0)
			print_error(ERR_DUP, NULL);
	}
	close(p_fd[0]);
	close(p_fd[1]);
	if (is_builtin(token.argv[0]) == TRUE)
		exe_builtin(token);
	else
	{
		if (execve(cmd_path, token.argv, p_env) < 0)
			print_error(ERR_EXE_FAIL, NULL);
	}
	exit(0);
}

static void	fork_and_execve(char *cmd_path, t_token token)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) < 0)
		print_error(ERR_PIPE, NULL);
	pid = fork();
	if (pid < 0)
		print_error(ERR_FORK, NULL);
	else if (pid > 0)
		parent_process(token, p_fd, pid);
	else
		child_process(cmd_path, token, p_fd);
}

static void	last_cmd_process(t_token *tokens)
{
	int		cmd_count;
	int		i;
	char	**cmd_path;

	cmd_count = get_cmd_count(tokens);
	cmd_path = token_to_cmd_path(tokens, cmd_count);
	i = 0;
	while (i < cmd_count - 1)
	{
		if (tokens[i].heredoc != NULL)
			heredoc_to_pipe(tokens[i]);
		else if (tokens[i].redirect_in != STDIN_FILENO)
		{
			if (dup2(tokens[0].redirect_in, STDIN_FILENO) < 0)
				print_error(ERR_DUP, NULL);
		}
		fork_and_execve(cmd_path[i], tokens[i]);
		free(cmd_path[i]);
		i++;
	}
	free(cmd_path);
	execve(cmd_path[cmd_count - 1], tokens[cmd_count - 1].argv, p_env);
}

int	do_commands(t_token *tokens)
{
	int		p_fd[2];
	pid_t	pid;
	int		status;

	if (pipe(p_fd) < 0)
		print_error(ERR_PIPE, NULL);
	pid = fork();
	if (pid < 0)
		print_error(ERR_FORK, NULL);
	else if (pid > 0)
	{
		if (waitpid(pid, &status, 0) == -1)
			print_error(ERR_WAITPID, "waitpid");
	}
	else
		last_cmd_process(tokens);
	return (status);
}
