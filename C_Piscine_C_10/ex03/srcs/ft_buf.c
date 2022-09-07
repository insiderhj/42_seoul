/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:09:26 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/06 09:34:24 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"
#include "hexdump.h"

void	ft_init_buf(t_buf *buf)
{
	buf->pos = 0;
	buf->len = 0;
	buf->skipped = 0;
}

void	ft_read_buf(int fd, t_buf *buf, int print_flag)
{
	while (read(fd, buf->str + buf->len, 1) > 0)
	{
		buf->len++;
		if (buf->len >= 16)
		{
			if (ft_strncmp(buf->prev, buf->str, 16) == 0)
			{
				if (buf->skipped == 0)
					ft_putstr("*\n");
				buf->skipped = 1;
			}
			else
			{
				ft_put_dump(*buf, print_flag);
				buf->skipped = 0;
			}
			buf->pos += buf->len;
			buf->len = 0;
			ft_strncpy(buf->prev, buf->str, 16);
		}
	}
}

void	ft_print_leftover(t_buf buf, int print_flag)
{
	if (buf.len)
	{
		ft_put_dump(buf, print_flag);
		buf.pos += buf.len;
	}
	ft_put_pos(buf.pos, print_flag);
}
