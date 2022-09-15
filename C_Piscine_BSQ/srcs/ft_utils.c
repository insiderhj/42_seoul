/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 01:24:08 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/15 02:47:52 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	valid_char(t_map *map, char c)
{
	return (c == map->box[EMPTY] || c == map->box[OBS]);
}

void	realloc_prev(t_map *map)
{
	int	*new;
	int	i;

	new = (int *)malloc(sizeof(int) * (map->malloc_size + 1000));
	i = 0;
	while (i < map->malloc_size)
	{
		new[i] = map->prev[i];
		i++;
	}
	map->malloc_size += 1000;
	free(map->prev);
	map->prev = new;
}

int	ft_free(char *str)
{
	free(str);
	return (0);
}
