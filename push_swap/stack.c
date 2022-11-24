/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:02:33 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 05:25:00 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

t_elem	*create_elem(int val)
{
	t_elem	*res;

	res = (t_elem *)malloc(sizeof(t_elem));
	if (!res)
		return (NULL);
	res->val = val;
	res->up = res;
	res->down = res;
	return (res);
}

int	insert_elem(t_stack *stack, char *str)
{
	int		val;
	t_elem	*e;

	if (!ft_check_num(stack, str))
		return (0);
	val = ft_atoi(str);
	e = create_elem(val);
	if (!e)
		return (0);
	push(&(stack->ta), e);
	rotate(&(stack->ta));
	return (1);
}

int	ft_find(t_elem *top, int val)
{
	t_elem	*temp;

	if (!top)
		return (0);
	if (top->val == val)
		return (1);
	temp = top->down;
	while (temp != top)
	{
		if (temp->val == val)
			return (1);
		temp = temp->down;
	}
	return (0);
}
