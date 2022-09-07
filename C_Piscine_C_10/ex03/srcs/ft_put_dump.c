/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 06:14:32 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/06 22:09:08 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "hexdump.h"

void	ft_put_pos(unsigned int pos, int print_flag)
{
	if (!pos)
		return ;
	ft_puthex(pos, 7 + print_flag);
	ft_putchar('\n');
}

void	ft_putbytes(char *buf, int len)
{
	int	i;

	i = 0;
	ft_putchar('|');
	while (i < len)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			ft_putchar(buf[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('|');
}

void	ft_put_byte(t_buf buf, int i, int print_flag)
{
	ft_puthex(buf.str[i], 2);
	if (print_flag || i != 15)
		ft_putchar(' ');
	if (print_flag && i % 8 == 7)
		ft_putchar(' ');
}

void	ft_put_space(int i, int print_flag)
{
	ft_putstr("  ");
	if (print_flag || i != 15)
		ft_putchar(' ');
	if (print_flag && i % 8 == 7)
		ft_putchar(' ');
}

void	ft_put_dump(t_buf buf, int print_flag)
{
	unsigned int	i;

	ft_puthex(buf.pos, 7 + print_flag);
	ft_putchar(' ');
	if (print_flag)
		ft_putchar(' ');
	i = 0;
	while (i < buf.len)
	{
		ft_put_byte(buf, i, print_flag);
		i++;
	}
	while (i < 0x10)
	{
		ft_put_space(i, print_flag);
		i++;
	}
	if (print_flag)
		ft_putbytes(buf.str, buf.len);
	ft_putchar('\n');
}
