/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:02:25 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/28 09:40:50 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
			if (col == 0 && (row == 0 || row == h - 1))
				ft_putchar('A');
			else if (col == w - 1 && (row == 0 || row == h - 1))
				ft_putchar('C');
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
