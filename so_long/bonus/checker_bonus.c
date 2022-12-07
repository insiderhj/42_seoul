/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:57:48 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/02 23:25:37 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	check_map(t_map *map)
{
	size_t	col;

	col = 0;
	if (map->height <= 2)
		return (0);
	if (map->exit_n != 1 || map->collectible_n == 0 || map->player_n != 1)
		return (0);
	while (map->map[0][col] && map->map[0][col] != '\n')
	{
		if (map->map[0][col] != '1')
			return (0);
		col++;
	}
	map->width = col;
	if (!check_rows(map))
		return (0);
	return (check_path(map));
}

int	check_rows(t_map *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < map->height)
	{
		if (ft_linelen(map->map[row]) != map->width
			|| map->map[row][0] != '1' || map->map[row][map->width - 1] != '1')
			return (0);
		col = 0;
		while (col < map->width)
		{
			if (!ft_strchr("01CEPX", map->map[row][col]))
				return (0);
			col++;
		}
		row++;
	}
	col = -1;
	while (++col < map->width)
	{
		if (map->map[map->height - 1][col] != '1')
			return (0);
	}
	return (1);
}

int	check_path(t_map *map)
{
	size_t	row;
	size_t	col;
	char	**path;

	path = init_path(map);
	if (!path)
		return (0);
	calc_path(map, path, map->exit.col, map->exit.row);
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if ((map->map[row][col] == 'P' || map->map[row][col] == 'C')
				&& path[row][col] == 'N')
				return (free_path(map, path));
			col++;
		}
		row++;
	}
	free_path(map, path);
	return (1);
}

char	**init_path(t_map *map)
{
	char	**res;
	size_t	row;
	size_t	col;

	res = malloc(sizeof(char *) * map->height);
	if (!res)
		return (0);
	row = 0;
	while (row < map->height)
	{
		res[row] = malloc(map->width);
		if (!res[row])
		{
			while (--row)
				free(res[row]);
			free(res);
			return (0);
		}
		col = 0;
		while (col < map->width)
			res[row][col++] = 'N';
		row++;
	}
	return (res);
}

void	calc_path(t_map *map, char **path, size_t col, size_t row)
{
	path[row][col] = 'Y';
	if (row > 0 && map->map[row - 1][col] != '1'
		&& map->map[row - 1][col] != 'X' && path[row - 1][col] != 'Y')
		calc_path(map, path, col, row - 1);
	if (col > 0 && map->map[row][col - 1] != '1'
		&& map->map[row][col - 1] != 'X' && path[row][col - 1] != 'Y')
		calc_path(map, path, col - 1, row);
	if (row + 1 < map->height && map->map[row + 1][col] != '1'
		&& map->map[row + 1][col] != 'X' && path[row + 1][col] != 'Y')
		calc_path(map, path, col, row + 1);
	if (col + 1 < map->width && map->map[row][col + 1] != '1'
		&& map->map[row][col + 1] != 'X' && path[row][col + 1] != 'Y')
		calc_path(map, path, col + 1, row);
}
