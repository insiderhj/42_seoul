/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 04:34:19 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 03:02:44 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <sys/errno.h>
#include <string.h>
#include <unistd.h>
#include "ft.h"
#include "hexdump.h"

void	ft_illegal_option(char *cmd, char opt)
{
	char	temp[2];

	temp[0] = opt;
	temp[1] = '\0';
	ft_puterr(basename(cmd), 0, "illegal option", temp);
	ft_puterr("usage", 0, "ft_hexdump [-C] [file ...]", 0);
}

int	check_option(char *cmd, char *opt)
{
	int	i;
	int	len;

	if (opt[0] == '-')
	{
		i = 1;
		len = ft_strlen(opt);
		while (i < len)
		{
			if (opt[i] != 'C')
			{
				ft_illegal_option(cmd, opt[i]);
				return (-1);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		chk;
	int		print_flag;

	print_flag = 0;
	if (argc == 1)
	{
		ft_dump_input(print_flag);
		return (0);
	}
	chk = check_option(argv[0], argv[1]);
	if (chk == -1)
		return (1);
	print_flag = chk;
	if (print_flag && argc == 2)
	{
		ft_dump_input(print_flag);
		return (0);
	}
	ft_dump_file(argc, argv, print_flag);
	return (0);
}
