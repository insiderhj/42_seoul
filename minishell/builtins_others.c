/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_others.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:56:34 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/29 10:20:50 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(t_token token)
{
	if (token.argc == 1)
		printf("\n");
	else if (ft_strcmp(token.argv[1], "-n") == 0)
		printf("%s", token.argv[2]);
	else
		printf("%s\n", token.argv[1]);
	exit(0);
}

void	builtin_cd(t_token token)
{
	if (token.argc >= 3)
		print_error(ERR_TOO_MANY_ARGS, "cd");
	else if (token.argc == 3)
		;// TODO : 예외처리(pwd에서 1번 인자를 찾아서 2번 인자로 치환)
	else
	{
		// TODO : 예외처리 (cd - 입력 시 이전 디렉토리로 이동)
		if (chdir(token.argv[1]) < 0)
			print_error(ERR_CHDIR, NULL);
	}
	exit(0);
}

void	builtin_pwd(t_token token)
{
	char	*path;

	path = getcwd(NULL, BUF_MAX);
	if (path == NULL)
		print_error(ERR_GET_CWD, NULL);
	printf("%s\n", path);
	free(path);
	exit(0);
}

void	builtin_env(char *prompt)
{
	size_t	i;
	char	*tmp;

	// TODO : 예외처리 (env + 명령어 -> 명령어 수행) => tokenizer에서 처리해야할지도...?
	i = 0;
	while (p_env[i] != NULL)
	{
		if (prompt == NULL)
			printf("%s\n", p_env[i]);
		else
		{
			tmp = ft_strjoin(prompt, p_env[i]);
			if (tmp == NULL)
				print_error(ERR_MALLOC, NULL);
			printf("%s\n", tmp);
			free(tmp);
		}
		i++;
	}
	exit(0);
}
