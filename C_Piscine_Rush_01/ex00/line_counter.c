/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:15:50 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 23:24:55 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_col_up(t_board *board, int col)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (i < board->size)
	{
		if (board->board[i][col] > max)
		{
			max = board->board[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_col_down(t_board *board, int col, int min)
{
	int	i;
	int	count;
	int	max;

	i = board->size - 1;
	count = 0;
	max = min;
	while (i >= 0)
	{
		if (board->board[i][col] > max)
		{
			max = board->board[i][col];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_row_left(t_board *board, int row)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (i < board->size)
	{
		if (board->board[row][i] > max)
		{
			max = board->board[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_row_right(t_board *board, int row, int min)
{
	int	i;
	int	count;
	int	max;

	i = board->size - 1;
	count = 0;
	max = min;
	while (i >= 0)
	{
		if (board->board[row][i] > max)
		{
			max = board->board[row][i];
			count++;
		}
		i--;
	}
	return (count);
}
