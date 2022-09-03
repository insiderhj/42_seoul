/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:16:36 by minkkang          #+#    #+#             */
/*   Updated: 2022/08/28 11:29:12 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

void	print_row1(int col)
{
	int	loc_col;

	loc_col = 0;
	while (loc_col < col)
	{
		if (loc_col == 0 || loc_col == col - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		loc_col++;
	}
}

void	print_row2(int col)
{
	int	loc_col;

	loc_col = 0;
	while (loc_col < col)
	{
		if (loc_col == 0)
		{
			ft_putchar('|');
		}
		else if (loc_col == col - 1)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
		loc_col++;
	}
}

void	rush(int col, int row)
{
	int	loc_row;

	if (row <= 0 || col <= 0)
		return ;
	loc_row = 0;
	while (loc_row < row)
	{
		if (loc_row == 0 || loc_row == row - 1)
		{
			print_row1(col);
		}
		else
		{
			print_row2(col);
		}
		ft_putchar('\n');
		loc_row++;
	}
}
