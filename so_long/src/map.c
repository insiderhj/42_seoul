/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:58:17 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/07 21:04:50 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <mlx.h>
#include "get_next_line.h"
#include "so_long.h"

int	create_map(t_map *map)
{
	map->map = NULL;
	map->win = NULL;
	map->exit_n = 0;
	map->collectible_n = 0;
	map->player_n = 0;
	map->width = 0;
	map->height = 0;
	map->exit.row = 0;
	map->exit.col = 0;
	map->p.row = 0;
	map->p.col = 0;
	map->enemy = malloc(sizeof(t_pos *));
	if (!map->enemy)
		return (0);
	map->enemy[0] = NULL;
	map->p_dir = DOWN;
	map->p_stat = ALIVE;
	map->movements = 0;
	map->frame = 0;
	return (1);
}

int	read_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!insert_line(map, line))
			return (0);
	}
	if (!check_map(map))
		return (0);
	return (1);
}

int	insert_line(t_map *map, char *line)
{
	size_t	i;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (map->height + 1));
	if (!new_map)
	{
		if (map->map)
			free(map->map);
		free(line);
		return (0);
	}
	i = 0;
	while (i < map->height)
	{
		new_map[i] = map->map[i];
		i++;
	}
	new_map[i] = line;
	if (map->map)
		free(map->map);
	map->map = new_map;
	map->height++;
	count_chars(map, line);
	return (1);
}

void	count_chars(t_map *map, char *line)
{
	size_t	col;

	col = 0;
	while (line[col])
	{
		if (line[col] == 'C')
			map->collectible_n++;
		else if (line[col] == 'E')
		{
			map->exit.row = map->height - 1;
			map->exit.col = col;
			map->exit_n++;
		}
		else if (line[col] == 'P')
		{
			map->p.row = map->height - 1;
			map->p.col = col;
			map->player_n++;
		}
		else if (line[col] == 'X')
			create_enemy(map, col, map->height - 1);
		col++;
	}
}

int	free_map(t_map *map)
{
	size_t	i;

	if (map->map)
	{
		i = 0;
		while (i < map->height)
			free(map->map[i++]);
		free(map->map);
	}
	if (map->enemy)
	{
		i = 0;
		while (map->enemy[i])
			free(map->enemy[i++]);
		free(map->enemy);
	}
	if (map->mlx && map->win)
		mlx_destroy_window(map->mlx, map->win);
	return (0);
}
