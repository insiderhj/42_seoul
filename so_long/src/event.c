/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:00:47 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/30 23:04:27 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"

int	key_press(int key, t_map *map)
{
	if (key == KEY_W)
	{
		map->p_dir = UP;
		move_player(map, 0, -1, "./img/p_up_0.xpm");
	}
	else if (key == KEY_A)
	{
		map->p_dir = LEFT;
		move_player(map, -1, 0, "./img/p_left_0.xpm");
	}
	else if (key == KEY_S)
	{
		map->p_dir = DOWN;
		move_player(map, 0, 1, "./img/p_down_0.xpm");
	}
	else if (key == KEY_D)
	{
		map->p_dir = RIGHT;
		move_player(map, 1, 0, "./img/p_right_0.xpm");
	}
	else if (key == KEY_ESC)
		exit_game(map);
	return (0);
}

int	move_player(t_map *map, int x, int y, char *img)
{
	if (map->map[map->p_row + y][map->p_col + x] == '1')
		return (0);
	put_img(map, map->p_col, map->p_row, "./img/floor.xpm");
	if (map->map[map->p_row][map->p_col] != 'E')
		map->map[map->p_row][map->p_col] = '0';
	else
		put_img(map, map->p_col, map->p_row, "./img/exit.xpm");
	map->p_row += y;
	map->p_col += x;
	if (map->map[map->p_row][map->p_col] == 'C')
		map->collectible_n--;
	else if (map->map[map->p_row][map->p_col] == 'X')
		map->p_stat = LOSE;
	else if (map->map[map->p_row][map->p_col] == 'E' && map->collectible_n == 0)
		map->p_stat = WIN;
	if (map->map[map->p_row][map->p_col] != '0')
		put_img(map, map->p_col, map->p_row, "./img/floor.xpm");
	put_img(map, map->p_col, map->p_row, img);
	map->movements++;
	show_movements(map);
	check_status(map);
	return (1);
}

void	check_status(t_map *map)
{
	if (map->p_stat == LOSE)
	{
		ft_printf("you lose!\ntotal movements: %d\n", map->movements);
		ft_printf("left collectibles: %d\n", map->collectible_n);
		exit_game(map);
	}
	else if (map->p_stat == WIN)
	{
		ft_printf("you win!\ntotal movements: %d\n", map->movements);
		ft_printf("left collectibles: %d\n", map->collectible_n);
		exit_game(map);
	}
}

int	exit_game(t_map *map)
{
	free_map(map);
	exit(0);
	return (0);
}
