/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:17:53 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/07 20:03:22 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_printf.h"
#include "so_long.h"

int	so_long(t_map *map)
{
	show_map(map);
	show_movements(map);
	mlx_hook(map->win, X_EVENT_KEY_RELEASE, 0, key_press, map);
	mlx_hook(map->win, X_EVENT_KEY_EXIT, 0, exit_game, map);
	mlx_loop_hook(map->mlx, animate, map);
	mlx_loop(map->mlx);
	return (free_map(map));
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2 || !ft_endswith(argv[1], ".ber"))
	{
		ft_printf("Error\nusage: so_long [.ber FILE]\n");
		return (1);
	}
	if (!create_map(&map))
		return (free_map(&map));
	if (!read_map(&map, argv[1]))
	{
		ft_printf("Error\ninvalid map\n");
		return (free_map(&map));
	}
	map.mlx = mlx_init();
	if (!map.mlx)
		return (free_map(&map));
	map.win = mlx_new_window(map.mlx,
			map.width * 32, map.height * 32 + 32, argv[0]);
	if (!map.win)
		return (free_map(&map));
	return (so_long(&map));
}
