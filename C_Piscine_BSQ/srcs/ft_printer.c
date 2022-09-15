/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:12:20 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/15 03:24:22 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int	is_full(t_map *map, int row, int col)
{
	if (map->answer_end.row >= row
		&& map->answer_end.row - map->answer_size < row
		&& map->answer_end.col >= col
		&& map->answer_end.col - map->answer_size < col)
		return (1);
	return (0);
}

int	ft_read(t_map *map, int fd, char **buf)
{
	if (fd == 0)
	{
		*buf = map->map + map->read_idx;
		map->read_idx += map->width;
		return (1);
	}
	*buf = (char *)malloc(sizeof(char) * (map->width + 1));
	return (read(fd, *buf, map->width + 1));
}

void	print_char(t_map *map, char *buf, int row, int col)
{
	if (buf[col] == map->box[OBS])
		ft_putchar(map->box[OBS]);
	else if (is_full(map, row, col))
		ft_putchar(map->box[FULL]);
	else
		ft_putchar(map->box[EMPTY]);
}

void	print_map(t_map *map, char *filename)
{
	int		fd;
	int		row;
	int		col;
	char	*buf;

	fd = open(filename, 0);
	if (filename == 0)
		fd = 0;
	if (fd < 0 || (fd != 0 && (!read_num(map, fd) || !read_box(map, fd))))
		return ;
	row = -1;
	while (++row < map->height)
	{
		col = -1;
		ft_read(map, fd, &buf);
		while (++col < map->width)
			print_char(map, buf, row, col);
		ft_putchar('\n');
		if (fd > 0)
			free(buf);
	}
	if (fd > 0)
		close(fd);
}
