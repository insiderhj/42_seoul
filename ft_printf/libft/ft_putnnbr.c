/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:55:24 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/14 20:48:23 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnnbr(long long n, int len)
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
	if (len > 0)
	{
		ft_putnnbr(div, len - 1);
		ft_putchar(mod + '0');
	}
}
