/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:35:47 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 23:20:24 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	res;

	neg = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = !neg;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (neg)
			res = res * 10 - (*str - '0');
		else
			res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putnbr(int nb)
{
	int	div;
	int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (nb < 0)
	{
		ft_putchar('-');
		div = -div;
		mod = -mod;
	}
	if (div > 0)
		ft_putnbr(div);
	ft_putchar(mod + '0');
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}
