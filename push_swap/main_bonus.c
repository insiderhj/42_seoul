/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 03:16:52 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 05:02:17 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	if (checker(stack) == -1)
		return (free_stack(stack, 1));
	check_result(stack);
	return (free_stack(stack, 0));
}
