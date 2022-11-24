/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:14:40 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 02:33:40 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	calc_min_ops(t_stack *stack)
{
	t_info	res;
	t_elem	*cur;
	size_t	rb_n;
	size_t	ra_n;

	res.op_count = SIZE_MAX;
	cur = stack->tb;
	ra_n = count_ra(stack, cur->val);
	rb_n = 0;
	res = update_min(stack, res, ra_n, rb_n);
	cur = cur->down;
	while (cur != stack->tb)
	{
		ra_n = count_ra(stack, cur->val);
		rb_n++;
		res = update_min(stack, res, ra_n, rb_n);
		cur = cur->down;
	}
	return (res);
}

size_t	count_ra(t_stack *stack, int val)
{
	size_t	count;
	t_elem	*cur;

	if (!stack)
		return (0);
	cur = stack->ta;
	count = 0;
	if ((cur->val > val && cur->up->val < val)
		|| (cur->val < cur->up->val && (val < cur->val || val > cur->up->val)))
		return (count);
	cur = cur->down;
	while (cur != stack->ta)
	{
		count++;
		if ((cur->val > val && cur->up->val < val)
			|| (cur->val < cur->up->val
				&& (val < cur->val || val > cur->up->val)))
			return (count);
		cur = cur->down;
	}
	return (count);
}

t_info	update_min(t_stack *stack, t_info res, size_t ra_n, size_t rb_n)
{
	size_t	rra_n;
	size_t	rrb_n;

	rra_n = stack->size_a - ra_n;
	rrb_n = stack->size_b - rb_n;
	if (res.op_count > ra_n + rrb_n)
		res = create_info(ra_n, 0, 0, rrb_n);
	if (res.op_count > rb_n + rra_n)
		res = create_info(0, rb_n, rra_n, 0);
	if (res.op_count > max(ra_n, rb_n))
		res = create_info(ra_n, rb_n, 0, 0);
	if (res.op_count > max(rra_n, rrb_n))
		res = create_info(0, 0, rra_n, rrb_n);
	return (res);
}

t_info	create_info(size_t ra_n, size_t rb_n, size_t rra_n, size_t rrb_n)
{
	t_info	res;
	size_t	min_ops;

	min_ops = max(ra_n, rb_n) + max(rra_n, rrb_n);
	res.op_count = min_ops;
	res.ra_n = ra_n;
	res.rb_n = rb_n;
	res.rra_n = rra_n;
	res.rrb_n = rrb_n;
	return (res);
}

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
