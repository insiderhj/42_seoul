/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insiderHJ <heejikim@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:57:17 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/15 12:14:08 by insiderHJ        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long long n, int uppercase)
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
	if (div > 0)
		ft_puthex(div, uppercase);
	if (uppercase)
		ft_putchar(upper[mod]);
	else
		ft_putchar(lower[mod]);
}
