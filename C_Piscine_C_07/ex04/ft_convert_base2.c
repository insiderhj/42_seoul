/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:34:00 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/31 16:15:25 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int	ft_valid_base(char *base)
{
	char	*ptr;

	if (ft_strlen(base) < 2)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-'
			|| *base == ' ' || *base == '\t' || *base == '\r'
			|| *base == '\n' || *base == '\v' || *base == '\f')
			return (0);
		ptr = base + 1;
		while (*ptr)
		{
			if (*base == *ptr)
				return (0);
			ptr++;
		}
		base++;
	}
	return (1);
}

int	ft_get_pos(char *base, char c)
{
	int	idx;

	idx = 0;
	while (*base)
	{
		if (*base == c)
			return (idx);
		idx++;
		base++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
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
	while (*str && ft_get_pos(base, *str) != -1)
	{
		if (neg)
			res = res * ft_strlen(base) - ft_get_pos(base, *str);
		else
			res = res * ft_strlen(base) + ft_get_pos(base, *str);
		str++;
	}
	return (res);
}

char	*ft_to_base(char *str, int *i, int nbr, char *base)
{
	int	div;
	int	mod;

	if (!str)
		str = (char *)malloc(34);
	div = nbr / ft_strlen(base);
	mod = nbr % ft_strlen(base);
	if (nbr < 0)
	{
		str[0] = '-';
		(*i)++;
		div = -div;
		mod = -mod;
	}
	if (div > 0)
	{
		ft_to_base(str, i, div, base);
		(*i)++;
	}
	str[*i] = *(base + mod);
	str[*i + 1] = 0;
	return (str);
}
