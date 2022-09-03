/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:52:38 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 21:41:17 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "rush01.h"

int	count_col_higher(t_board *board, int col, int n)
{
	int	count;
	int	i;

	count = 0;
	i = n + 1;
	while (i < board->size + 1)
	{
		if (board->col_mark[col][i] == false)
			count++;
		i++;
	}
	return (count);
}

int	count_col_lower(t_board *board, int col, int n)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < n)
	{
		if (board->col_mark[col][i] == false)
			count++;
		i++;
	}
	return (count);
}

int	count_row_higher(t_board *board, int row, int n)
{
	int	count;
	int	i;

	count = 0;
	i = n + 1;
	while (i < board->size + 1)
	{
		if (board->row_mark[row][i] == false)
			count++;
		i++;
	}
	return (count);
}

int	count_row_lower(t_board *board, int row, int n)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < n)
	{
		if (board->row_mark[row][i] == false)
			count++;
		i++;
	}
	return (count);
}
