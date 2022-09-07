/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:53:34 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 03:07:04 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <libgen.h>
#include <sys/errno.h>
#include "ft.h"
#include "hexdump.h"

int	ft_open(char *cmd, char *filename)
{
	int	fd;

	fd = open(filename, 0);
	if (fd < 0)
	{
		ft_puterr(basename(cmd), filename, strerror(errno), 0);
		return (fd);
	}
	return (fd);
}

void	ft_check_error(int argc, char **argv)
{
	char	temp;

	read(-1, &temp, 1);
	ft_puterr(basename(argv[0]), argv[argc - 1], strerror(errno), 0);
}

void	ft_dump_file(int argc, char **argv, int print_flag)
{
	t_buf	buf;
	int		count;
	int		fd;
	int		i;

	ft_init_buf(&buf);
	i = 1 + print_flag;
	count = 0;
	while (i < argc)
	{
		fd = ft_open(argv[0], argv[i]);
		if (fd > 0)
		{
			ft_read_buf(fd, &buf, print_flag);
			close(fd);
			count++;
		}
		i++;
	}
	ft_print_leftover(buf, print_flag);
	if (count == 0)
		ft_check_error(argc, argv);
}
