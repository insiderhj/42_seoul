/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:49:57 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/30 22:32:33 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(size_t n)
{
	char	*res;
	int		len;
	int		i;

	len = ft_nbrlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
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
