/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:58:17 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/02 23:45:51 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "so_long.h"

t_map	*create_map(void)
{
	t_map	*res;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	res->map = NULL;
	res->exit_n = 0;
	res->collectible_n = 0;
	res->player_n = 0;
	res->width = 0;
	res->height = 0;
	res->exit.row = 0;
	res->exit.col = 0;
	res->p.row = 0;
	res->p.col = 0;
	res->enemy = malloc(sizeof(t_pos *));
	if (!res->enemy)
		return (NULL);
	res->enemy[0] = NULL;
	res->p_dir = DOWN;
	res->p_stat = ALIVE;
	res->movements = 0;
	res->frame = 0;
	return (res);
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

	if (map)
	{
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
		free(map);
	}
	return (0);
}
