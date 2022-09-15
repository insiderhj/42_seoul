/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:27:56 by guryu             #+#    #+#             */
/*   Updated: 2022/09/15 12:41:35 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

int	read_num(t_map *map, int fd)
{
	char	c;
	int		res;

	res = 0;
	while (1)
	{
		if (!read(fd, &c, 1))
			return (0);
		if (c >= '0' && c <= '9')
		{
			res = res * 10 + (c - '0');
			if (res < 0)
				return (0);
		}
		else if (c >= 32 && c <= 126)
		{
			map->box[0] = c;
			break ;
		}
		else
			return (0);
	}
	map->height = res;
	return (res);
}

int	read_box(t_map *map, int fd)
{
	char	c;
	int		i;
	int		len;

	len = 1;
	while (len < 3 && read(fd, &c, 1) && c >= 32 && c <= 126)
	{
		i = 0;
		while (i < len)
		{
			if (map->box[i] == c)
				return (0);
			i++;
		}
		map->box[len] = c;
		len++;
	}
	if (len < 3 || !read(fd, &c, 1) || c != '\n')
		return (0);
	return (1);
}

void	update_answer(t_map *map, int row, int col, int size)
{
	map->answer_end.row = row;
	map->answer_end.col = col;
	map->answer_size = size;
}

void	put_max(t_map *map, int row, int col)
{
	int	min;

	if (!col)
		min = 0;
	else
	{
		min = map->cur[col - 1];
		if (map->prev[col - 1] < min)
			min = map->prev[col - 1];
	}
	if (map->prev[col] < min)
		min = map->prev[col];
	if (min == -1)
		min = 0;
	map->cur[col] = min + 1;
	if (min + 1 > map->answer_size)
		update_answer(map, row, col, min + 1);
}

int	read_file(t_map **map, int fd)
{

	*map = create_map();
	if (!*map)
		return (0);
	if (!read_num(*map, fd) || !read_box(*map, fd) || !read_map(*map, fd))
	{
		return (0);
	}
	return (1);
}
