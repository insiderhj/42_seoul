/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:22:19 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/28 16:30:19 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(char **env, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(env[i++]);
	free(env);
}

char	**copy_env(char **env, size_t size, size_t idx)
{
	char	**n_env;
	size_t	i;

	n_env = malloc(sizeof(char *) * (size + 1));
	if (n_env == NULL)
		print_error(ERR_MALLOC, NULL);
	i = 0;
	while (i < idx)
	{
		n_env[i] = ft_strdup(env[i]);
		if (n_env[i] == NULL)
		{
			free_env(n_env, i);
			print_error(ERR_MALLOC, NULL);
		}
		i++;
	}
	return (n_env);
}

void	make_private_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	p_env = copy_env(env, i, i);
	p_env[i] = NULL;
}
