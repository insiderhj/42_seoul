/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:57:36 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 23:27:56 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

/*
 * input: input string to number array
 * row_mark, col_mark: mark if there is already a number on that line
 * ex) row_mark[i][j] == 1 : row i has item j
 */
typedef struct board {
	int	board[9][9];
	int	size;
	int	*input;
	int	row_mark[9][10];
	int	col_mark[9][10];
}	t_board;

// ft_functions
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_count_part(char *str);
int		*ft_split(char *str, int size);

// board.c
/*
 * init board
 * MUST free board->input after process
 */
int		init_board(t_board *board, char *input);
void	print_board(t_board *board);

// line_counter.c
int		count_col_up(t_board *board, int col);
int		count_col_down(t_board *board, int col, int min);
int		count_row_left(t_board *board, int row);
int		count_row_right(t_board *board, int row, int min);

// mark_counter.c
int		count_col_higher(t_board *board, int col, int n);
int		count_col_lower(t_board *board, int col, int n);
int		count_row_higher(t_board *board, int row, int n);
int		count_row_lower(t_board *board, int row, int n);

// checker.c
int		check_col_up(t_board *board, int col, int n);
int		check_col_down(t_board *board, int col, int n);
int		check_row_left(t_board *board, int row, int n);
int		check_row_right(t_board *board, int row, int n);

// checker2.c
int		count_col_possible(t_board *board, int col);
int		count_row_possible(t_board *board, int row);

// rush01.c
/*
 * recursive function!
 */
int		place_box(t_board *board, int idx);

#endif
