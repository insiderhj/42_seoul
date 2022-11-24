/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:29:07 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 04:45:01 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack)
{
	t_info	info;

	while (stack->size_a > 2)
		do_op(stack, "pb", 1);
	while (stack->size_a < stack->size_total)
	{
		info = calc_min_ops(stack);
		push_a(stack, info);
	}
	final_rotate(stack);
}

void	push_a(t_stack *stack, t_info info)
{
	while (info.ra_n && info.rb_n)
	{
		do_op(stack, "rr", 1);
		info.ra_n--;
		info.rb_n--;
	}
	while (info.rra_n && info.rrb_n)
	{
		do_op(stack, "rrr", 1);
		info.rra_n--;
		info.rrb_n--;
	}
	repeat_op(stack, "ra", info.ra_n);
	repeat_op(stack, "rb", info.rb_n);
	repeat_op(stack, "rra", info.rra_n);
	repeat_op(stack, "rrb", info.rrb_n);
	do_op(stack, "pa", 1);
}

void	final_rotate(t_stack *stack)
{
	t_elem	*cur;
	size_t	ra_n;

	if (!(stack->ta))
		return ;
	cur = stack->ta;
	ra_n = 0;
	if (cur->val < cur->up->val)
		return ;
	cur = cur->down;
	while (cur != stack->ta)
	{
		ra_n++;
		if (cur->val < cur->up->val)
			break ;
		cur = cur->down;
	}
	if (ra_n < stack->size_a - ra_n)
		repeat_op(stack, "ra", ra_n);
	else
		repeat_op(stack, "rra", stack->size_a - ra_n);
}

void	repeat_op(t_stack *stack, char *op, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		do_op(stack, op, 1);
		i++;
	}
}
