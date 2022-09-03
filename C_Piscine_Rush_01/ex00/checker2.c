/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:16:21 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 23:36:13 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	get_max(int *arr, int size)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i++ < size)
	{
		if (!*arr++)
			max++;
	}
	return (max);
}

int	get_left_count(int *arr, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (!arr[i])
			count++;
		i++;
	}
	return (count);
}

int	count_col_possible(t_board *board, int col)
{
	int	highest;
	int	exist_count;
	int	left_count;

	highest = get_max(board->col_mark[col], board->size);
	exist_count = count_col_down(board, col, highest);
	left_count = get_left_count(board->col_mark[col], board->size);
	return (exist_count + left_count);
}

int	count_row_possible(t_board *board, int row)
{
	int	highest;
	int	exist_count;
	int	left_count;

	highest = get_max(board->row_mark[row], board->size);
	exist_count = count_row_right(board, row, highest);
	left_count = get_left_count(board->row_mark[row], board->size);
	return (exist_count + left_count);
}
