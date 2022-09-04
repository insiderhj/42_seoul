/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:52:26 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 21:36:37 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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
	ft_putchar('\n');
}

void	ft_putnbr(int nb)
{
	int	div;
	int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (nb < 0)
	{
		write(1, "-", 1);
		div = -div;
		mod = -mod;
	}
	if (div > 0)
		ft_putnbr(div);
	ft_putchar(mod + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putstr(par->copy);
		par++;
	}
}
