/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:03:32 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/08 23:21:39 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp) ())
{
	t_list	*i;
	t_list	*cur;
	void	*data;

	i = *begin_list;
	if (!i || !i->next)
		return ;
	while (i->next)
	{
		cur = *begin_list;
		while (cur->next)
		{
			if (cmp(cur->data, cur->next->data) > 0)
			{
				data = cur->data;
				cur->data = cur->next->data;
				cur->next->data = data;
			}
			cur = cur->next;
		}
		i = i->next;
	}
}
