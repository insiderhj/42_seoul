/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:49:57 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/09 18:59:19 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		res++;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		i;

	len = ft_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	i = len - 1;
	while (n)
	{
		if (n > 0)
			res[i--] = n % 10 + '0';
		else
			res[i--] = -(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
