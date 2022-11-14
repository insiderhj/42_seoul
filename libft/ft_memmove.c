/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:24:02 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/11 15:38:15 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			pos;
	int				dir;

	if (dst == src)
		return (dst);
	pd = dst;
	ps = (unsigned char *)src;
	pos = 0;
	dir = 1;
	if (dst >= src)
	{
		pos = len - 1;
		dir = -1;
	}
	while (len)
	{
		pd[pos] = ps[pos];
		pos += dir;
		len--;
	}
	return (dst);
}
