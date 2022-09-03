/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:20:56 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/03 21:40:57 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush01.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_count_part(char *str)
{
	int	res;
	int	len;

	res = 0;
	len = 0;
	while (*str)
	{
		if (!is_space(*str))
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

void	ft_insert_split_part(int *res, char *str)
{
	int		i;
	int		len;
	char	*start_ptr;

	i = 0;
	len = 0;
	start_ptr = str;
	while (*str)
	{
		if (!is_space(*str))
			len++;
		else
		{
			if (len != 0)
				res[i++] = ft_atoi(start_ptr);
			start_ptr = str + 1;
			len = 0;
		}
		str++;
	}
	if (len != 0)
		res[i] = ft_atoi(start_ptr);
}

int	*ft_split(char *str, int size)
{
	int	*res;
	int	npart;
	int	i;

	npart = ft_count_part(str);
	res = (int *)malloc(sizeof(int) * (npart));
	i = 0;
	while (i <= npart)
	{
		res[i] = 0;
		i++;
	}
	ft_insert_split_part(res, str);
	i = 0;
	while (i < npart)
	{
		if (res[i] <= 0 || res[i] > size)
		{
			free(res);
			return (0);
		}
		i++;
	}
	return (res);
}
