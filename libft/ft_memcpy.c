/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:16:32 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/11 14:45:31 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	if (dst == src)
		return (dst);
	pd = dst;
	ps = (unsigned char *)src;
	while (n)
	{
		*pd = *ps;
		pd++;
		ps++;
		n--;
	}
	return (dst);
}
