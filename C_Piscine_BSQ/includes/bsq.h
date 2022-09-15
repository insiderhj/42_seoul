/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:36:24 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/15 22:54:33 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

enum e_box
{
	EMPTY = 0,
	OBS = 1,
	FULL = 2,
};

typedef struct pos
{
	int	row;
	int	col;
}	t_pos;

typedef struct map
{
	char	box[3];
	int		width;
	int		height;
	char	*line;

	int		map_size;
	int		read_idx;
	char	*map;

	int		malloc_size;
	int		*prev;
	int		*cur;

	int		answer_size;
	t_pos	answer_end;
}	t_map;

// ft_exception.c
int		words_left(int fd);

// ft_file_reader.c
int		read_num(t_map *map, int fd);
int		read_box(t_map *map, int fd);
void	update_answer(t_map *map, int row, int col, int size);
void	put_max(t_map *map, int row, int col);
int		read_file(t_map **map, int fd);

// ft_map_reader.c
int		save_input(t_map *map, int fd, char c);
int		read_first_line(t_map *map, int fd);
int		input_item(t_map *map, int row, int col, int c);
void	move_prev(t_map *map);
int		read_map(t_map *map, int fd);

// ft_map.c
t_map	*create_map(void);
void	free_map(t_map *map);

// ft_printer.c
int		is_full(t_map *map, int row, int col);
int		ft_read(t_map *map, int fd, char **c);
void	print_char(t_map *map, char *buf, int row, int col);
void	print_map(t_map *map, char *filename);

// ft_utils.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		valid_char(t_map *map, char c);
void	realloc_prev(t_map *map);
int		ft_free(char *str);

#endif
