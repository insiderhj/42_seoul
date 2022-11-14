/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:59:33 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/11 20:20:35 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_part(const char *str, char c)
{
	size_t	res;

	res = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			res++;
		while (*str && *str != c)
			str++;
	}
	return (res);
}

char	*ft_dup_part(const char *str, char c)
{
	char	*res;
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, len + 1);
	return (res);
}

char	**ft_insert_part(char **res, size_t npart, const char *str, char c)
{
	size_t	i;

	i = 0;
	while (i < npart)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			res[i] = ft_dup_part(str, c);
			if (!res[i])
			{
				while (i > 0)
					free(res[--i]);
				free(res);
				return (NULL);
			}
		}
		while (*str && *str != c)
			str++;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	size_t	npart;

	npart = ft_count_part(str, c);
	res = (char **)malloc(sizeof(char *) * (npart + 1));
	if (!res)
		return (NULL);
	return (ft_insert_part(res, npart, str, c));
}
