/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 03:17:56 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 03:35:37 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*res;

	res = (t_stack *)malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->ta = NULL;
	res->tb = NULL;
	res->size_total = 0;
	res->size_a = 0;
	res->size_b = 0;
	return (res);
}

void	free_elems(t_elem *start)
{
	t_elem	*cur;
	t_elem	*next;

	if (!start)
		return ;
	cur = start;
	next = cur->down;
	free(cur);
	while (next != start)
	{
		cur = next;
		next = cur->down;
		free(cur);
	}
}

int	free_stack(t_stack *stack, int print_error)
{
	if (stack)
	{
		free_elems(stack->ta);
		free_elems(stack->tb);
		free(stack);
	}
	if (print_error)
		write(2, "Error\n", 6);
	return (0);
}
