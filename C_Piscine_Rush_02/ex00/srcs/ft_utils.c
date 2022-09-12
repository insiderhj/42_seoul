/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:35:49 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 21:19:52 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ' || c == '\0');
}

int	ft_atoi(char *num)
{
	int	res;

	res = 0;
	while (!is_space(*num) && *num != ':')
	{
		res = res * 10 + (*num - '0');
		num++;
	}
	if ((res > 20 && res % 10) || res > 100)
		return (-1);
	return (res);
}

int	ft_add_buf(char **buf, char c)
{
	int		len;
	char	*tmp;

	if (!*buf)
	{
		*buf = (char *)malloc(2);
		if (!buf)
			return (0);
		(*buf)[0] = c;
		(*buf)[1] = '\0';
	}
	else
	{
		len = ft_strlen(*buf);
		tmp = (char *)malloc(len + 2);
		if (!tmp)
			return (ft_free(buf));
		ft_strcpy(tmp, *buf);
		tmp[len] = c;
		tmp[len + 1] = '\0';
		free(*buf);
		*buf = tmp;
	}
	return (1);
}

int	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = 0;
	return (0);
}
