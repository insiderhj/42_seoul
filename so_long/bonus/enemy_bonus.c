/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:27:18 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/05 02:53:35 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "so_long.h"

void	create_enemy(t_map *map, size_t col, size_t row)
{
	size_t	enemy_size;
	size_t	i;
	t_pos	**new_list;
	t_pos	*new_enemy;

	enemy_size = 0;
	while (map->enemy[enemy_size])
		enemy_size++;
	new_list = malloc(sizeof(t_pos *) * (enemy_size + 2));
	if (!new_list)
		exit_game(map);
	new_enemy = malloc(sizeof(t_pos));
	if (!new_enemy)
		exit_game(map);
	new_enemy->col = col;
	new_enemy->row = row;
	i = -1;
	while (++i < enemy_size)
		new_list[i] = map->enemy[i];
	new_list[i++] = new_enemy;
	new_list[i] = NULL;
	free(map->enemy);
	map->enemy = new_list;
}

void	move_enemy(t_map *map, int move)
{
	size_t	i;

	i = 0;
	while (map->enemy[i])
	{
		if (map->map[map->enemy[i]->row][map->enemy[i]->col + move] == '0')
		{
			put_img(map, map->enemy[i]->col, map->enemy[i]->row,
				"./img/floor.xpm");
			map->map[map->enemy[i]->row][map->enemy[i]->col] = '0';
			map->enemy[i]->col += move;
			put_img(map, map->enemy[i]->col, map->enemy[i]->row,
				"./img/enemy_0.xpm");
			map->map[map->enemy[i]->row][map->enemy[i]->col] = 'X';
			if (map->p.row == map->enemy[i]->row
				&& map->p.col == map->enemy[i]->col)
			{
				ft_printf("you lose!\ntotal movements: %d\n", map->movements);
				ft_printf("left collectibles: %d\n", map->collectible_n);
				exit_game(map);
			}
		}
		i++;
	}
}
