/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:57:17 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/14 21:01:05 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnhex(unsigned long long n, int len, int uppercase)
{
	char		*upper;
	char		*lower;
	long long	div;
	long long	mod;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	div = n / 0x10;
	mod = n % 0x10;
	if (n < 0)
	{
		ft_putchar('-');
		div = -div;
		mod = -mod;
	}
	if (len > 0)
	{
		ft_putnhex(div, len - 1, uppercase);
		if (uppercase)
			ft_putchar(upper[mod]);
		else
			ft_putchar(lower[mod]);
	}
}
