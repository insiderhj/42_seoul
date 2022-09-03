/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:51:47 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 23:36:35 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	delete_box(t_board *board, int row, int col, int n)
{
	board->board[row][col] = 0;
	board->row_mark[row][n] = 0;
	board->col_mark[col][n] = 0;
}

int	insert_box(t_board *board, int row, int col, int n)
{
	if (board->row_mark[row][n] || board->col_mark[col][n])
		return (0);
	board->board[row][col] = n;
	board->row_mark[row][n] = 1;
	board->col_mark[col][n] = 1;
	if (!check_col_up(board, col, n)
		|| !check_col_down(board, col, n)
		|| !check_row_left(board, row, n)
		|| !check_row_right(board, row, n))
	{
		delete_box(board, row, col, n);
		return (0);
	}
	return (1);
}

int	place_box(t_board *board, int idx)
{
	int	n;
	int	row;
	int	col;

	row = idx / board->size;
	col = idx % board->size;
	n = 0;
	while (++n <= board->size)
	{
		if (!insert_box(board, row, col, n))
			continue ;
		if (idx < board->size * board->size - 1)
		{
			if (place_box(board, idx + 1))
				return (1);
			delete_box(board, row, col, n);
		}
		else
			return (1);
	}
	return (0);
}
