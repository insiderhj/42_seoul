/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:55:14 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/08 23:50:57 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp) ())
{
	t_list	*new;
	t_list	*cur;

	cur = *begin_list;
	new = ft_create_elem(data);
	if (!cur || cmp(cur->data, data) >= 0)
	{
		new->next = *begin_list;
		*begin_list = new;
		return ;
	}
	while (cur)
	{
		if (!cur->next || cmp(cur->next->data, data) >= 0)
		{
			new->next = cur->next;
			cur->next = new;
			return ;
		}
		cur = cur->next;
	}
}
