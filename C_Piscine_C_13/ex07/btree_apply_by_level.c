/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 23:56:31 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/12 19:51:33 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	increase_level(void ****items)
{
	int		len;
	int		i;
	void	***tmp;

	len = 0;
	while ((*items)[len])
		len++;
	tmp = (void ***)malloc(sizeof(void **) * (len + 2));
	i = 0;
	while (i < len)
	{
		tmp[i] = (*items)[i];
		i++;
	}
	tmp[i] = (void **)malloc(sizeof(void *));
	tmp[i][0] = 0;
	tmp[i + 1] = 0;
	free(*items);
	*items = tmp;
}

void	put_item(void ***level, void *item)
{
	int		len;
	int		i;
	void	**tmp;

	len = 0;
	while ((*level)[len])
		len++;
	tmp = (void **)malloc(sizeof(void *) * (len + 2));
	i = 0;
	while (i < len)
	{
		tmp[i] = (*level)[i];
		i++;
	}
	tmp[i] = item;
	tmp[i + 1] = 0;
	free(*level);
	*level = tmp;
}

void	btree_scan(t_btree *root, void ****items, int level)
{
	if (!root)
		return ;
	if (!(*items)[level])
		increase_level(items);
	put_item(&(*items)[level], root->item);
	btree_scan(root->left, items, level + 1);
	btree_scan(root->right, items, level + 1);
}

void	free_items(void ***items)
{
	int	level;

	level = 0;
	while (items[level])
	{
		free(items[level]);
		level++;
	}
	free(items);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf) (void *item, int current_level, int is_first_elem))
{
	void	***items;
	int		level;
	int		idx;

	items = (void ***)malloc(sizeof(void **));
	items[0] = 0;
	btree_scan(root, &items, 0);
	level = 0;
	while (items[level])
	{
		idx = 0;
		while (items[level][idx])
		{
			applyf(items[level][idx], level, !idx);
			idx++;
		}
		level++;
	}
	free_items(items);
}
