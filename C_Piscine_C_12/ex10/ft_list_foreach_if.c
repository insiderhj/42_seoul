/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:35:44 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/08 22:48:15 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f) (void *),
								void *data_ref, int (*cmp) ())
{
	while (begin_list)
	{
		if (!cmp(begin_list->data, data_ref))
			f(begin_list->data);
		begin_list = begin_list->next;
	}
}
