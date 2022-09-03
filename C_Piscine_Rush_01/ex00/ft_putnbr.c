/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:47:11 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 21:40:03 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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
