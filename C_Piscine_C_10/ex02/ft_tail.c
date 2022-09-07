/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:05:48 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 02:41:21 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>
#include "ft.h"

int	ft_put_usage(char *cmd)
{
	ft_puterr(basename(cmd), 0, "option requires an argument", "c");
	ft_puterr("usage", 0, "ft_tail [-c #] [file ...]", 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_display_info	info;
	int				i;

	if (argc < 3)
		return (ft_put_usage(argv[0]));
	info.input_len = ft_getnum(argv[2]);
	if (info.input_len < 0)
		return (ft_puterr(basename(argv[0]), 0, "illegal offset", argv[2]));
	if (argc == 3)
		return (ft_tail_input(argv[0], info.input_len));
	i = 3;
	info.pad = 0;
	while (i < argc)
	{
		if (ft_display_file(argc, argv[0], argv[i], info))
			info.pad = 1;
		i++;
	}
	return (0);
}
