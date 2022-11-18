/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:43 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/18 23:52:29 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2)
	{
		if (*s1 == 0 || idx + 1 >= n)
			return (0);
		s1++;
		s2++;
		idx++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
