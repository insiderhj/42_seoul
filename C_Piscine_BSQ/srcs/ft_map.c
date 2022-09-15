/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 01:23:10 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/15 03:12:16 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

t_map	*create_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->line = 0;
	map->map_size = 0;
	map->read_idx = 0;
	map->map = (char *)malloc(sizeof(char) * 1000);
	map->malloc_size = 1000;
	map->prev = (int *)malloc(sizeof(int) * 1000);
	map->cur = 0;
	map->answer_size = 0;
	map->answer_end.row = -1;
	map->answer_end.col = -1;
	return (map);
}

void	free_map(t_map *map)
{
	free(map->prev);
	free(map->map);
	free(map);
}
