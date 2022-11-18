/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:55:24 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/16 23:03:07 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long long n)
{
	long long	div;
	long long	mod;

	div = n / 10;
	mod = n % 10;
	if (n < 0)
	{
		div = -div;
		mod = -mod;
	}
	if (div > 0)
	{
		if (ft_putnbr(div) == -1)
			return (-1);
	}
	return (ft_putchar(mod + '0'));
}
