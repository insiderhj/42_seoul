/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:56:34 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/28 16:33:41 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_validation(char *curr_env)
{
	char	*tmp;

	if (ft_isalpha(curr_env[0]) != 0)
	{
		tmp = ft_strjoin("unset: ", curr_env);
		print_error(ERR_INVALID_PARAM, tmp);
		free(tmp);
		return (-1);
	}
	return (0);
}

void	env_export(char *exp_str)
{
	size_t	size;
	char	**n_env;

	size = 0;
	while (p_env[size] != NULL)
		size++;
	n_env = copy_env(p_env, size + 1, size - 1);
	n_env[size - 1] = ft_strdup(exp_str);
	if (n_env[size - 1] == NULL)
		print_error(ERR_MALLOC, NULL);
	n_env[size] = ft_strdup(n_env[size - 1]);
	if (n_env[size] == NULL)
		print_error(ERR_MALLOC, NULL);
	n_env[size + 1] = NULL;
	free_env(p_env, size);
	p_env = n_env;
}

void	builtin_export(t_token token)
{
	size_t	i;
	char	**n_env;

	if (token.argc == 1)
		builtin_env("declare -x ");
	i = 0;
	while (i < token.argc)
	{
		if (check_validation(token.argv[i]) < 0)
			continue ;
		env_export(token.argv[i]);
		i++;
	}
	exit(0);
}
