/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:57:17 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/16 23:02:37 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long long n, int uppercase)
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
		if (ft_putchar('-') == -1)
			return (-1);
		div = -div;
		mod = -mod;
	}
	if (div > 0)
	{
		if (ft_puthex(div, uppercase) == -1)
			return (-1);
	}
	if (uppercase)
		return (ft_putchar(upper[mod]));
	else
		return (ft_putchar(lower[mod]));
}
