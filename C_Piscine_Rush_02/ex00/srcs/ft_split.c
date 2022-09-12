/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:51:59 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 22:56:31 by hyogshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush02.h"

int	count_zeros(int len)
{
	int	res;

	res = 3 - len % 3;
	if (res == 3)
		return (0);
	return (res);
}

void	ft_fill_str(char *str, char *res, int idx, int len)
{
	int	zeros;
	int	pos;
	int	i;

	zeros = count_zeros(len);
	pos = 0;
	if (idx == 0)
	{
		while (zeros)
		{
			res[pos] = '0';
			zeros--;
			pos++;
		}
	}
	i = 0;
	while (i + pos < 3)
	{
		if (idx == 0)
			res[i + pos] = str[i];
		else
			res[i] = str[idx * 3 - zeros + i];
		i++;
	}
}

char	**ft_split(char *str)
{
	char	**res;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	res = (char **)malloc(sizeof(char *) * ((len + 2) / 3 + 1));
	if (!res)
		return (0);
	i = -1;
	while (++i < (len + 2) / 3)
	{
		res[i] = (char *)malloc(sizeof(char) * 3);
		if (!(res[i]))
		{
			j = 0;
			while (j < i)
				free(res[j++]);
			free(res);
			return (0);
		}
		ft_fill_str(str, res[i], i, len);
	}
	res[i] = 0;
	return (res);
}
