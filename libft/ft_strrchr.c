/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:57:45 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/11 14:51:12 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == ch)
		return ((char *)s);
	return (NULL);
}
