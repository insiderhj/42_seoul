/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:12:38 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/11 14:41:24 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	i;
	size_t	len;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	i = 0;
	len = 0;
	while (s1[start + i])
	{
		if (!ft_strchr(set, s1[start + i]) && ft_strchr(set, s1[start + i + 1]))
			len = i + 1;
		i++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + start, len + 1);
	return (res);
}
