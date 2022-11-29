/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:57:48 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/30 02:24:16 by heejikim         ###   ########.fr       */
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
	return (check_rows(map));
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
