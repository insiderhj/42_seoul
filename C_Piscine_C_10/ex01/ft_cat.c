/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:45:09 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 03:48:36 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>
#include "ft.h"

int	main(int argc, char **argv)
{
	int		i;
	char	buf;

	if (argc == 1)
	{
		buf = 0;
		while (read(0, &buf, 1) > 0)
			ft_putchar(buf);
		return (0);
	}
	i = 1;
	while (i < argc)
		ft_display_file(basename(argv[0]), argv[i++]);
	return (0);
}
