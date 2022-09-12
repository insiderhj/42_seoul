/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:50:45 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/08 22:56:44 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp) (),
							void (*free_fct) (void *))
{
	t_list	*prev;
	t_list	*cur;
	t_list	*tmp;

	cur = *begin_list;
	prev = 0;
	while (cur)
	{
		if (!cmp(cur->data, data_ref))
		{
			tmp = cur->next;
			if (prev)
				prev->next = cur->next;
			else
				*begin_list = cur->next;
			free_fct(cur->data);
			free(cur);
			cur = tmp;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
