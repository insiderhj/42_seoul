/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:33:20 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/30 20:22:49 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_list(char *list)
{
	write(1, list, 10);
	ft_putchar('\n');
}

int	ft_put_queen(char *list, int row, int count)
{
	int		prev;
	char	i;

	i = '0';
	while (i <= '9')
	{
		list[row] = i;
		prev = 0;
		while (prev < row && list[prev] != i
			&& i - list[prev] != row - prev && i - list[prev] != prev - row)
			prev++;
		if (prev == row)
		{
			if (row < 9)
				count = ft_put_queen(list, row + 1, count);
			else
			{
				count++;
				ft_print_list(list);
			}
		}
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	list[11];

	list[10] = '\0';
	return (ft_put_queen(list, 0, 0));
}
