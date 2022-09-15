/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:00:56 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/15 22:54:31 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

void	bsq(int fd, char *filename)
{
	t_map	*map;

	map = 0;
	if (fd >= 0 && read_file(&map, fd))
		print_map(map, filename);
	else
		ft_putstr("map error\n");
	if (fd >= 0)
	{
		free_map(map);
		if (fd > 0)
			close(fd);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc == 1)
	{
		bsq(0, 0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], 0);
		bsq(fd, argv[i]);
		i++;
	}
	return (0);
}
