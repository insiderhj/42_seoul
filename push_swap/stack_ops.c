/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:01:49 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 05:20:41 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_elem **top, t_elem *new)
{
	t_elem	*old_top;

	if (!new)
		return ;
	if (!*top)
	{
		*top = new;
		(*top)->up = *top;
		(*top)->down = *top;
		return ;
	}
	old_top = *top;
	*top = new;
	(*top)->up = old_top->up;
	(*top)->up->down = *top;
	(*top)->down = old_top;
	old_top->up = *top;
}

t_elem	*pop(t_elem **top)
{
	t_elem	*res;

	if (!*top)
		return (NULL);
	res = *top;
	if (res->up == res)
	{
		*top = NULL;
		return (res);
	}
	res->up->down = res->down;
	res->down->up = res->up;
	*top = res->down;
	return (res);
}

void	swap(t_elem **top)
{
	t_elem	*e1;
	t_elem	*e2;

	if (!*top)
		return ;
	e1 = *top;
	e2 = e1->down;
	if (e2->down == e1)
	{
		rotate(top);
		return ;
	}
	e2->up = e1->up;
	e1->down = e2->down;
	e2->down = e1;
	e1->up = e2;
	e1->down->up = e1;
	e2->up->down = e2;
	*top = e2;
}

void	rotate(t_elem **top)
{
	if (!*top)
		return ;
	*top = (*top)->down;
}

void	rrotate(t_elem **top)
{
	if (!*top)
		return ;
	*top = (*top)->up;
}
