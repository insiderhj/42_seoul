/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:48:24 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/29 13:16:01 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_and_prompt(void)
{
	char	*line;
	char	*prompt;
	char	*curr_path;

	curr_path = getcwd(NULL, BUF_MAX);
	prompt = ft_strjoin(ft_strrchr(curr_path, '/') + 1, "$ ");
	free(curr_path);
	line = readline(prompt);
	free(prompt);
	return (line);
}

static int	check_prev_status(t_token *tokens, int prev_stat)
{
	if (get_cmd_count(tokens) == 1 && tokens[0].argc == 1
		&& ft_strcmp(tokens[0].argv[0], "$?") == 0)
	{
		printf("%d\n", ((*(int *)&(prev_stat)) >> 8) & 0x000000ff);
		return (1);
	}
	return (0);
}

int	main(int ac, __attribute__((unused)) char **av, char **env)
{
	char	*line;
	t_token	*tokens;
	int		prev_stat;

	prev_stat = 0;
	if (ac != 1)
	{
		return (1);
	}
	make_private_env(env);
	// TODO : ctrl-C, ctrl-D, ctrl-\ signal 구현
	while (1)
	{
		line = read_and_prompt();
		if (line != NULL && *line != '\0')
			add_history(line);
		// tokens = tokenize(line);
		free(line);
		// if (check_prev_status(tokens, prev_stat) == 1)
		// 	prev_stat = 127;
		// else
		// 	prev_stat = do_commands(tokens);
		// TODO : add function to free tokens and close fds
	}
	return (0);
}
