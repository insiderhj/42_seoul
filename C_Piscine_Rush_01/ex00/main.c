/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:50:13 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 21:40:33 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

int	main(int argc, char **argv)
{
	t_board	board;

	if (argc != 2 || !init_board(&board, argv[1]))
	{
		ft_putstr("Error\n");
		return (-1);
	}
	if (place_box(&board, 0))
		print_board(&board);
	else
		ft_putstr("Error\n");
	free(board.input);
	return (0);
}
