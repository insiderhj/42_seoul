/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:55:24 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/09 20:08:50 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	div = n / 10;
	mod = n % 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		div = -div;
		mod = -mod;
	}
	if (div > 0)
		ft_putnbr_fd(div, fd);
	ft_putchar_fd(mod + '0', fd);
}
