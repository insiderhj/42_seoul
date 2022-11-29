/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:56:17 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/30 02:25:42 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate(t_map *map)
{
	map->frame++;
	if (map->frame % 2000 == 0)
	{
		animate_player(map, map->frame / 2000 % 4);
	}
	return (1);
}

void	animate_player(t_map *map, int idx)
{
	put_img(map, map->p_col, map->p_row, "./img/floor.xpm");
	if (map->p_dir == UP || map->p_dir == DOWN)
		animate_vertical(map, idx);
	else
		animate_horizontal(map, idx);
}

void	animate_vertical(t_map *map, int idx)
{
	if (map->p_dir == UP)
	{
		if (idx == 0)
			put_img(map, map->p_col, map->p_row, "./img/p_up_0.xpm");
		else if (idx == 1)
			put_img(map, map->p_col, map->p_row, "./img/p_up_1.xpm");
		else if (idx == 2)
			put_img(map, map->p_col, map->p_row, "./img/p_up_2.xpm");
		else
			put_img(map, map->p_col, map->p_row, "./img/p_up_3.xpm");
	}
	else
	{
		if (idx == 0)
			put_img(map, map->p_col, map->p_row, "./img/p_down_0.xpm");
		else if (idx == 1)
			put_img(map, map->p_col, map->p_row, "./img/p_down_1.xpm");
		else if (idx == 2)
			put_img(map, map->p_col, map->p_row, "./img/p_down_2.xpm");
		else
			put_img(map, map->p_col, map->p_row, "./img/p_down_3.xpm");
	}
}

void	animate_horizontal(t_map *map, int idx)
{
	if (map->p_dir == LEFT)
	{
		if (idx == 0)
			put_img(map, map->p_col, map->p_row, "./img/p_left_0.xpm");
		else if (idx == 1)
			put_img(map, map->p_col, map->p_row, "./img/p_left_1.xpm");
		else if (idx == 2)
			put_img(map, map->p_col, map->p_row, "./img/p_left_2.xpm");
		else
			put_img(map, map->p_col, map->p_row, "./img/p_left_3.xpm");
	}
	else
	{
		if (idx == 0)
			put_img(map, map->p_col, map->p_row, "./img/p_right_0.xpm");
		else if (idx == 1)
			put_img(map, map->p_col, map->p_row, "./img/p_right_1.xpm");
		else if (idx == 2)
			put_img(map, map->p_col, map->p_row, "./img/p_right_2.xpm");
		else
			put_img(map, map->p_col, map->p_row, "./img/p_right_3.xpm");
	}
}
