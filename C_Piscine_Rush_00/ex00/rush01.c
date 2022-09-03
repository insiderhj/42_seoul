/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:33:45 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/28 09:48:01 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_vertex(int row, int col)
{
	if (row == 0)
	{
		if (col == 0)
			ft_putchar('/');
		else
			ft_putchar('\\');
	}
	else
	{
		if (col == 0)
			ft_putchar('\\');
		else
			ft_putchar('/');
	}
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
				ft_putchar('*');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
