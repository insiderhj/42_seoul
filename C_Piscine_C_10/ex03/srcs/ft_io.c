/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:41:36 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/06 09:43:06 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_puterr(char *cmd, char *op, char *err, char *info)
{
	ft_putstr(cmd);
	ft_putstr(": ");
	if (op)
	{
		ft_putstr(op);
		ft_putstr(": ");
	}
	ft_putstr(err);
	if (info)
	{
		ft_putstr(" -- ");
		ft_putstr(info);
	}
	ft_putchar('\n');
	return ;
}

void	ft_puthex(unsigned int n, int len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (len > 1)
		ft_puthex(n / 0x10, len - 1);
	ft_putchar(hex[n % 0x10]);
}
