/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:41:01 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/28 09:54:22 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	rush(int w, int h);

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	to_int(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	w;
	int	h;

	if (argc < 2)
	{
		ft_putstr("argc must be 2\n");
		return (-1);
	}
	w = to_int(argv[1]);
	h = to_int(argv[2]);
	if (w < 0 || h < 0)
	{
		ft_putstr("argument must be a natural number\n");
		return (-1);
	}
	rush(w, h);
	return (0);
}
