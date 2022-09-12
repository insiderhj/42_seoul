/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:04:07 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/08 23:50:02 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
								int (*cmp) ())
{
	t_list	*cur;
	t_list	*prev;
	t_list	*tmp;

	cur = *begin_list1;
	prev = 0;
	while (begin_list2)
	{
		if (!cur || cmp(cur->data, begin_list2->data) >= 0)
		{
			tmp = begin_list2->next;
			if (!prev)
				*begin_list1 = begin_list2;
			else
				prev->next = begin_list2;
			prev = begin_list2;
			begin_list2->next = cur;
			begin_list2 = tmp;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
