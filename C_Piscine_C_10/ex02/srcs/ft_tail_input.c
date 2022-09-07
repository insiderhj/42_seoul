/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:34:14 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/06 21:51:43 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>
#include <libgen.h>
#include "ft.h"

void	ft_puttail(char *str)
{
	if (!*str)
		return ;
	if (*str == '\n')
	{
		ft_putstr("^D\n");
		str++;
	}
	else if (*(str + 1) == '\n')
	{
		ft_putchar(*str);
		ft_putchar('D');
		str++;
	}
	ft_putstr(str);
}

int	ft_tail_input(char *cmd, long long input_len)
{
	char		*buf;
	char		*temp;
	long long	len;

	buf = malloc(input_len + 1);
	if (!buf)
	{
		ft_puterr(basename(cmd), "malloc", strerror(errno), 0);
		return (1);
	}
	temp = buf;
	len = 0;
	while (read(0, buf, 1) > 0)
	{
		buf++;
		if (len < input_len)
			len++;
	}
	*buf = 0;
	ft_puttail(buf - len);
	free(temp);
	return (0);
}
