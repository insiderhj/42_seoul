/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:19:47 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 02:40:50 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include "ft.h"

int	ft_open(char *cmd, int *fd, char *filename)
{
	*fd = open(filename, 0);
	if (*fd < 0)
	{
		ft_puterr(basename(cmd), filename, strerror(errno), 0);
		return (0);
	}
	return (1);
}

int	ft_filelen(char *cmd, long long *len, char *filename)
{
	char		buf;
	int			fd;

	if (!ft_open(cmd, &fd, filename))
		return (0);
	*len = 0;
	while (read(fd, &buf, 1) > 0)
		(*len)++;
	close(fd);
	return (1);
}

void	ft_put_filename(char *filename, int pad)
{
	if (pad)
		ft_putchar('\n');
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}

int	ft_display_file(int argc, char *cmd, char *filename, t_display_info info)
{
	char		*buf;
	char		*temp;
	long long	len;
	int			fd;

	if (!ft_open(cmd, &fd, filename) || !ft_filelen(cmd, &len, filename))
		return (0);
	buf = malloc(len + 1);
	if (!buf)
	{
		ft_puterr(basename(cmd), "malloc", strerror(errno), 0);
		return (0);
	}
	temp = buf;
	while (read(fd, buf, 1) > 0)
		buf++;
	*buf = 0;
	if (info.input_len > len)
		info.input_len = len;
	if (argc > 4)
		ft_put_filename(filename, info.pad);
	ft_putstr(buf - info.input_len);
	close(fd);
	free(temp);
	return (1);
}
