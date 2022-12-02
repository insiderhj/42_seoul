/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:00:14 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/02 23:52:47 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_printf.h"
#include "so_long.h"

void	put_img(t_map *map, size_t col, size_t row, char *file)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx, file, &img_width, &img_height);
	mlx_put_image_to_window(map->mlx, map->win, img, col * 32, row * 32);
}

void	show_map(t_map *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			put_img(map, col, row, "./img/floor.xpm");
			if (map->map[row][col] == '1')
				put_img(map, col, row, "./img/wall.xpm");
			else if (map->map[row][col] == 'C')
				put_img(map, col, row, "./img/item.xpm");
			else if (map->map[row][col] == 'E')
				put_img(map, col, row, "./img/exit.xpm");
			else if (map->map[row][col] == 'X')
				put_img(map, col, row, "./img/enemy_0.xpm");
			else if (map->map[row][col] == 'P')
				put_img(map, col, row, "./img/p_down_0.xpm");
			col++;
		}
		row++;
	}
}

void	show_movements(t_map *map)
{
	size_t	col;
	char	*movements_str;

	col = 0;
	while (col < map->width)
	{
		put_img(map, col, map->height, "./img/black.xpm");
		col++;
	}
	mlx_string_put(map->mlx, map->win, 0, map->height * 32,
		0xffffff, "movements:");
	movements_str = ft_itoa(map->movements);
	if (!movements_str)
		exit_game(map);
	mlx_string_put(map->mlx, map->win, 100, map->height * 32,
		0xffffff, movements_str);
	free(movements_str);
}
