/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:20:56 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/31 20:24:14 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_find(char *charset, char c)
{
	int	idx;

	idx = 0;
	while (*charset)
	{
		if (*charset == c)
			return (idx);
		idx++;
		charset++;
	}
	return (-1);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	dest = malloc(n + 1);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

int	ft_count_part(char *str, char *charset)
{
	int	res;
	int	len;

	res = 0;
	len = 0;
	while (*str)
	{
		if (ft_find(charset, *str) == -1)
			len++;
		else if (len != 0)
		{
			res++;
			len = 0;
		}
		str++;
	}
	if (len != 0)
		res++;
	return (res);
}

void	ft_insert_split_part(char **res, char *str, char *charset)
{
	int		i;
	int		len;
	char	*start_ptr;

	i = 0;
	len = 0;
	start_ptr = str;
	while (*str)
	{
		if (ft_find(charset, *str) == -1)
		{
			len++;
		}
		else
		{
			if (len != 0)
				res[i++] = ft_strndup(start_ptr, len);
			start_ptr = str + 1;
			len = 0;
		}
		str++;
	}
	if (len != 0)
		res[i] = ft_strndup(start_ptr, len);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		npart;

	npart = ft_count_part(str, charset);
	res = (char **)malloc(sizeof(char *) * (npart + 1));
	res[npart] = 0;
	ft_insert_split_part(res, str, charset);
	return (res);
}
