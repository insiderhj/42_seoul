/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:14:37 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/15 12:15:24 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int	save_input(t_map *map, int fd, char c)
{
	char	*new;
	int		i;

	if (fd != 0)
		return (1);
	if (map->map_size % 1000 == 999)
	{
		new = (char *)malloc(sizeof(char) * (map->map_size + 1 + 1000));
		i = 0;
		while (i < map->map_size)
		{
			new[i] = map->map[i];
			i++;
		}
		free(map->map);
		map->map = new;
	}
	map->map[map->map_size] = c;
	map->map[map->map_size + 1] = '\0';
	map->map_size++;
	return (1);
}

int	read_first_line(t_map *map, int fd)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) && save_input(map, fd, c) && c != '\n')
	{
		if (i >= map->malloc_size)
			realloc_prev(map);
		if (c == map->box[EMPTY])
		{
			if (map->answer_size == 0)
				update_answer(map, 0, i, 1);
			map->prev[i] = 1;
		}
		else if (c == map->box[OBS])
			map->prev[i] = -1;
		else
			return (0);
		i++;
	}
	if (c != '\n')
		return (0);
	map->width = i;
	return (i);
}

int	input_item(t_map *map, int row, int col, int c)
{
	if (c == map->box[EMPTY])
	{
		put_max(map, row, col);
		return (1);
	}
	else if (c == map->box[OBS])
	{
		map->cur[col] = -1;
		return (1);
	}
	else
		return (0);
}

void	move_prev(t_map *map)
{
	free(map->prev);
	map->prev = map->cur;
}

int	read_map(t_map *map, int fd)
{
	int		row;
	int		col;
	int		len;

	if (!read_first_line(map, fd))
		return (0);
	row = 0;
	while (++row < map->height)
	{
		col = -1;
		map->cur = (int *)malloc(sizeof(int) * map->width);
		map->line = (char *)malloc(sizeof(char) * (map->width + 1));
		len = read(fd, map->line, map->width + 1);
		while (len == map->width + 1 && save_input(map, fd, map->line[++col])
			&& col < map->width && valid_char(map, map->line[col]))
		{
			if (!input_item(map, row, col, map->line[col]))
				return (ft_free(map->line));
		}
		move_prev(map);
		if (col != map->width || map->line[col] != '\n')
			return (ft_free(map->line));
		free(map->line);
	}
	return (!words_left(fd));
}
