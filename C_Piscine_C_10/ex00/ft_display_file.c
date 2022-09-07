/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:19:47 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/06 18:45:38 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	buf;

	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], 0);
	if (fd < 0)
	{
		ft_putstr("Cannot read file.\n");
		return (1);
	}
	while (read(fd, &buf, 1) > 0)
		ft_putchar(buf);
	close(fd);
	return (0);
}
