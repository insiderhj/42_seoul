/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:43:38 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 04:44:00 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_op(t_stack *stack, char *op, int print)
{
	if (print)
		print_op(op);
	if (!ft_strcmp(op, "sa"))
		swap(&(stack->ta));
	else if (!ft_strcmp(op, "sb"))
		swap(&(stack->tb));
	else if (!ft_strcmp(op, "ss"))
	{
		swap(&(stack->ta));
		swap(&(stack->tb));
	}
	else
		return (do_op_push(stack, op));
	return (1);
}

int	do_op_push(t_stack *stack, char *op)
{
	if (!ft_strcmp(op, "pa"))
	{
		if (stack->size_b)
		{
			stack->size_a++;
			stack->size_b--;
			push(&(stack->ta), pop(&(stack->tb)));
		}
	}
	else if (!ft_strcmp(op, "pb") && stack->size_a)
	{
		if (stack->size_a)
		{
			stack->size_b++;
			stack->size_a--;
			push(&(stack->tb), pop(&(stack->ta)));
		}
	}
	else
		return (do_op_rotate(stack, op));
	return (1);
}

int	do_op_rotate(t_stack *stack, char *op)
{
	if (!ft_strcmp(op, "ra"))
		rotate(&(stack->ta));
	else if (!ft_strcmp(op, "rb"))
		rotate(&(stack->tb));
	else if (!ft_strcmp(op, "rr"))
	{
		rotate(&(stack->ta));
		rotate(&(stack->tb));
	}
	else if (!ft_strcmp(op, "rra"))
		rrotate(&(stack->ta));
	else if (!ft_strcmp(op, "rrb"))
		rrotate(&(stack->tb));
	else if (!ft_strcmp(op, "rrr"))
	{
		rrotate(&(stack->ta));
		rrotate(&(stack->tb));
	}
	else
		return (0);
	return (1);
}
