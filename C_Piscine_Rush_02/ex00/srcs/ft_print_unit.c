/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:38:42 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 17:58:54 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush02.h"

int	ft_print_str(char *str, int print_space)
{
	int		i;

	i = 0;
	while (str[i])
	{	
		write(1, &str[i], 1);
		i++;
	}
	if (print_space)
		ft_putchar(' ');
	return (0);
}

void	ft_print_hundred(t_dict *dict, char *str, int last_space)
{
	int	print_space;

	print_space = 0;
	if (str[1] != '0' || str[2] != '0' || last_space)
		print_space = 1;
	if (str[0] != '0')
	{
		ft_print_str(dict->ones[str[0] - '0'], 1);
		ft_print_str(dict->hundred, print_space);
	}
}

void	ft_print_ten(t_dict *dict, char *str, int last_space)
{
	int	print_space;

	print_space = 0;
	if ((str[1] != '1' && str[2] != '0') || last_space)
		print_space = 1;
	if (str[1] != '0')
	{
		if (str[1] == '1')
			ft_print_str(dict->teens[str[2] - '0'], print_space);
		else
			ft_print_str(dict->tens[str[1] - '0'], print_space);
	}
}

void	ft_print_one(t_dict *dict, char *str, int last_space)
{
	int	print_space;

	print_space = 0;
	if (last_space)
		print_space = 1;
	if (str[2] != '0' && str[1] != '1')
		ft_print_str(dict->ones[str[2] - '0'], print_space);
}

void	ft_print_unit(t_dict *dict, char *str, int len, int has_next)
{
	int	last_space;

	last_space = 0;
	if (len > 1 || has_next)
		last_space = 1;
	ft_print_hundred(dict, str, last_space);
	ft_print_ten(dict, str, last_space);
	ft_print_one(dict, str, last_space);
}
