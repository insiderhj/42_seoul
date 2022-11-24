/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:37:37 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 05:30:47 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (argc == 1)
		return (0);
	stack = create_stack();
	if (!stack)
		return (free_stack(stack, 1));
	i = 0;
	while (++i < argc)
	{
		if (!insert_elem(stack, argv[i]))
			return (free_stack(stack, 1));
	}
	stack->size_total = i - 1;
	stack->size_a = i - 1;
	push_swap(stack);
	return (free_stack(stack, 0));
}
