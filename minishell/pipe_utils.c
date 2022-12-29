/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:59:04 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/29 09:50:59 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmd_count(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].argc != 0 && tokens[i].argv != NULL)
		i++;
	return (i);
}

char	**get_cmd_paths(void)
{
	size_t	i;
	char	**path;
	char	*tmp;

	path = NULL;
	i = 0;
	while (p_env[i] != NULL)
	{
		if (ft_strncmp(p_env[i], "PATH=", 5) == 0)
		{
			path = ft_split(p_env[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (path == NULL || path[0] == NULL)
		print_error(ERR_ENV_PATH, NULL);
	i = 0;
	while (path[i] != NULL)
	{
		tmp = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i++] = tmp;
	}
	return (path);
}

char	*find_cmd_path(char **path, t_token token)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	if (is_builtin(token.argv[0]) == TRUE || access(token.argv[0], X_OK) == 0)
		tmp = token.argv[0];
	while (path[i] != NULL && tmp == NULL)
	{
		tmp = ft_strjoin(path[i], token.argv[0]);
		if (access(tmp, X_OK) == 0)
			break ;
		free(tmp);
		tmp = NULL;
		i++;
	}
	if (tmp == NULL && access(token.argv[0], X_OK) != 0)
		print_error(ERR_NO_CMD, token.argv[0]);
	return (tmp);
}

char	**token_to_cmd_path(t_token *tokens, int cmd_count)
{
	int		i;
	char	**path;
	char	**cmd_path;

	path = get_cmd_paths();
	cmd_path = malloc(sizeof(char *) * cmd_count);
	if (cmd_path == NULL)
		print_error(ERR_MALLOC, NULL);
	i = 0;
	while (i < cmd_count)
	{
		cmd_path[i] = find_cmd_path(path, tokens[i]);
		i++;
	}
	i = 0;
	while (path[i] != NULL)
		free(path[i++]);
	free(path);
	return (cmd_path);
}

void	heredoc_to_pipe(t_token token)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) < 0)
		print_error(ERR_PIPE, NULL);
	pid = fork();
	if (pid < 0)
		print_error(ERR_FORK, NULL);
	else if (pid > 0)
	{
		if (waitpid(pid, NULL, 0) == -1)
			print_error(ERR_EXE_FAIL, NULL);
		if (dup2(p_fd[READ], STDIN_FILENO) < 0)
			print_error(ERR_DUP, NULL);
		close(p_fd[0]);
		close(p_fd[1]);
	}
	else
	{
		write(p_fd[WRITE], token.heredoc, ft_strlen(token.heredoc));
		close(p_fd[0]);
		close(p_fd[1]);
		exit(0);
	}
}
