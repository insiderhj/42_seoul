/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:19:47 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/06 03:55:01 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include <unistd.h>
#include "ft.h"

void	ft_display_file(char *cmd, char *filename)
{
	char	buf;
	int		fd;

	fd = open(filename, 0);
	if (fd < 0)
	{
		ft_puterr(cmd, filename, strerror(errno));
		return ;
	}
	buf = 0;
	while (read(fd, &buf, 1) > 0)
	{
		ft_putchar(buf);
	}
	close(fd);
}
