/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongheek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:04:50 by yongheek          #+#    #+#             */
/*   Updated: 2022/08/28 13:07:15 by yongheek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_vertex(int row, int col)
{
	if (row == 0)
		ft_putchar('A');
	else
		ft_putchar('C');
}

void	rush(int w, int h)
{
	int	row;
	int	col;

	if (w <= 0 || h <= 0)
		return ;
	row = 0;
	col = 0;
	while (row < h)
	{
		col = 0;
		while (col < w)
		{
			if ((row == 0 || row == h - 1) && (col == 0 || col == w - 1))
				print_vertex(row, col);
			else if (row == 0 || row == h - 1 || col == 0 || col == w - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
