/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:00:14 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/30 03:05:15 by heejikim         ###   ########.fr       */
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
	mlx_put_image_to_window(map->mlx, map->win, img, col * 16, row * 32);
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
			put_img(map, col * 2, row, "./img/floor.xpm");
			if (map->map[row][col] == '1')
				put_img(map, col * 2, row, "./img/wall.xpm");
			else if (map->map[row][col] == 'C')
				put_img(map, col * 2, row, "./img/item.xpm");
			else if (map->map[row][col] == 'E')
				put_img(map, col * 2, row, "./img/exit.xpm");
			else if (map->map[row][col] == 'X')
				put_img(map, col * 2, row, "./img/enemy_0.xpm");
			else if (map->map[row][col] == 'P')
				put_img(map, col * 2, row, "./img/p_down_0.xpm");
			col++;
		}
		row++;
	}
}

void	show_movements(t_map *map)
{
	put_img(map, 0, map->height, "./img/movements.xpm");
	show_digits(map, 9, map->movements);
}

void	show_digits(t_map *map, size_t off, size_t num)
{
	char	*digit_file;

	if (num >= 10)
	{
		show_digits(map, off, num / 10);
		off += 1;
	}
	digit_file = malloc(16);
	if (!digit_file)
		exit_game(map);
	ft_strcpy(digit_file, "./img/nbr_0.xpm");
	digit_file[10] = num % 10 + '0';
	put_img(map, off, map->height, digit_file);
	free(digit_file);
}
