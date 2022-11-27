/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:19:07 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/27 02:29:35 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	unsigned char	*p;

	ch = c;
	p = (unsigned char *)s;
	while (*p)
	{
		if (*p == ch)
			return ((char *)p);
		p++;
	}
	if (!ch)
		return ((char *)p);
	return (NULL);
}
