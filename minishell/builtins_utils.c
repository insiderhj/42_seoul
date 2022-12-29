/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:05:35 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/29 09:06:49 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(const char *cmd)
{
	const char	*builtins[] = {"echo", "cd", "pwd", \
		"exit", "env", "export", "unset"};
	size_t		i;

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(cmd, builtins[i]) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	exe_builtin(t_token token)
{
	if (ft_strcmp(token.argv[0], "echo") == 0)
		builtin_echo(token);
	else if (ft_strcmp(token.argv[0], "ch") == 0)
		builtin_cd(token);
	else if (ft_strcmp(token.argv[0], "pwd") == 0)
		builtin_pwd(token);
	else if (ft_strcmp(token.argv[0], "exit") == 0)
		builtin_exit(token);
	else if (ft_strcmp(token.argv[0], "export") == 0)
		builtin_export(token);
	else if (ft_strcmp(token.argv[0], "unset") == 0)
		builtin_unset(token);
	else if (ft_strcmp(token.argv[0], "env") == 0)
		builtin_env(NULL);
	else
		print_error(ERR_NO_CMD, NULL);
}
