/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:56:34 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/28 16:31:46 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_validation(char *curr_env)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (curr_env[i] != '\0')
	{
		if (ft_isalnum(curr_env[i]) != 0)
		{
			tmp = ft_strjoin("unset: ", curr_env);
			print_error(ERR_INVALID_PARAM, tmp);
			free(tmp);
			return (-1);
		}
		i++;
	}
	if (i == 0)
	{
		print_error(ERR_INVALID_PARAM, "unset: ");
		return (-1);
	}
	return (0);
}

static void	env_unset(size_t idx)
{
	size_t	size;
	char	**n_env;

	size = 0;
	while (p_env[size] != NULL)
		size++;
	n_env = copy_env(p_env, size - 1, idx);
	while (idx < size - 1)
	{
		n_env[idx] = ft_strdup(p_env[idx + 1]);
		if (n_env[idx] == NULL)
			print_error(ERR_MALLOC, NULL);
		idx++;
	}
	n_env[idx] = NULL;
	free_env(p_env, size);
	p_env = n_env;
}

static void	env_find_key(char *key)
{
	size_t	i;
	char	**n_env;

	i = 0;
	while (p_env[i] != NULL)
	{
		if (ft_strncmp(p_env[i], key, ft_strlen(key)) == 0)
		{
			env_unset(i);
			return ;
		}
		i++;
	}
}

void	builtin_unset(t_token token)
{
	char	**n_env;
	size_t	i;

	if (token.argc == 1)
		return ;
	i = 1;
	while (i < token.argc)
	{
		if (check_validation(token.argv[i]) < 0)
			continue ;
		env_find_key(token.argv[i]);
		i++;
	}
	p_env = n_env;
	exit(0);
}
