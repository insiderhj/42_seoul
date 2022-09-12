/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:39:58 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/08 23:44:51 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	int		len;
	t_list	*cur;

	cur = begin_list;
	len = 0;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	i = 0;
	while (i < len - 1)
	{
		cur = begin_list;
		j = 0;
		while (j < len - 1 - i)
		{
			swap(&(cur->data), &(cur->next->data));
			cur = cur->next;
			j++;
		}
		i++;
	}
}
