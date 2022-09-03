/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:44:59 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 23:36:16 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_col_up(t_board *board, int col, int n)
{
	int	input;
	int	up_count;
	int	higher_count;

	input = board->input[col];
	up_count = count_col_up(board, col);
	higher_count = count_col_higher(board, col, n);
	if (up_count > input || up_count + higher_count < input)
		return (0);
	return (1);
}

int	check_col_down(t_board *board, int col, int n)
{
	int	input;
	int	down_count;
	int	higher_count;
	int	possible_count;

	input = board->input[board->size + col];
	down_count = count_col_down(board, col, 0);
	higher_count = count_col_higher(board, col, n);
	possible_count = count_col_possible(board, col);
	if (possible_count < input || (down_count > input && higher_count == 0))
		return (0);
	return (1);
}

int	check_row_left(t_board *board, int row, int n)
{
	int	input;
	int	left_count;
	int	higher_count;

	input = board->input[board->size * 2 + row];
	left_count = count_row_left(board, row);
	higher_count = count_row_higher(board, row, n);
	if (left_count > input || left_count + higher_count < input)
		return (0);
	return (1);
}

int	check_row_right(t_board *board, int row, int n)
{
	int	input;
	int	right_count;
	int	higher_count;
	int	possible_count;

	input = board->input[board->size * 3 + row];
	right_count = count_row_right(board, row, 0);
	higher_count = count_row_higher(board, row, n);
	possible_count = count_row_possible(board, row);
	if (possible_count < input || (right_count > input && higher_count == 0))
		return (0);
	return (1);
}
