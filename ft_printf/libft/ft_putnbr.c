/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insiderHJ <heejikim@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:55:24 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/15 12:14:56 by insiderHJ        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long n)
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
		ft_putnbr(div);
	ft_putchar(mod + '0');
}
