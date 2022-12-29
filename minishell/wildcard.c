/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:07:55 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/29 13:45:46 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_cwd_items_count(char *curr_path)
{
	struct dirent	*item;
	size_t			i;
	DIR				*dirp;

	dirp = opendir(curr_path);
	if (dirp == NULL)
		print_error(ERR_OPENDIR, NULL);
	i = 0;
	while (1)
	{
		item = readdir(dirp);
		if (item == NULL)
			break ;
		i++;
		item = NULL;
	}
	closedir(dirp);
	return (i);
}

char	**get_cwd_items(void)
{
	char	**items;
	size_t	items_cnt;
	size_t	i;
	DIR		*dirp;
	char	*curr_path;

	curr_path = getcwd(NULL, BUF_MAX);
	if (curr_path == NULL)
		print_error(ERR_GET_CWD, NULL);
	items_cnt = get_cwd_items_count(curr_path);
	items = malloc(sizeof(char *) * (items_cnt));
	if (items == NULL)
		print_error(ERR_MALLOC, NULL);
	dirp = opendir(curr_path);
	if (dirp == NULL)
		print_error(ERR_OPENDIR, NULL);
	i = 0;
	while (i < items_cnt)
		items[i++] = ft_strdup(readdir(dirp)->d_name);
	free(curr_path);
	closedir(dirp);
	return (items);
}
