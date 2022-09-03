/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:15:40 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 18:16:33 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	fill_board(t_board *board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 10)
		{
			board->row_mark[i][j] = 0;
			board->col_mark[i][j] = 0;
			if (j < 9)
				board->board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	init_board(t_board *board, char *input)
{
	int	input_size;

	input_size = ft_count_part(input);
	if (input_size % 4 || input_size == 0 || input_size > 36)
		return (0);
	board->size = ft_count_part(input) / 4;
	board->input = ft_split(input, board->size);
	if (!board->input)
		return (0);
	fill_board(board);
	return (1);
}

void	print_board(t_board *board)
{
	int	i;
	int	j;

	i = 0;
	while (i < board->size)
	{
		j = 0;
		while (j < board->size)
		{
			ft_putnbr(board->board[i][j]);
			if (j < board->size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
