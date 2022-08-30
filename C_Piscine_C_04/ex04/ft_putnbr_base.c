/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:39:46 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/30 00:43:57 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if (*base == '+' || *base == '-')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	div;
	int	mod;

	if (!ft_valid_base(base))
		return ;
	len = ft_strlen(base);
	div = nbr / len;
	mod = nbr % len;
	if (nbr < 0)
	{
		write(1, "-", 1);
		div = -div;
		mod = -mod;
	}
	if (div > 0)
		ft_putnbr_base(div, base);
	write(1, base + mod, 1);
}
