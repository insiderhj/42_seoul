/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:27:51 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 18:51:44 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	return_err(char *str)
{
	ft_putstr(str);
	return (1);
}

int	check_num(t_dict *dict, char *nbr)
{
	int		len;
	char	*ptr;

	ptr = nbr;
	while (*ptr)
	{
		if (*ptr < '0' || *ptr > '9')
		{
			ft_putstr("Error\n");
			free_dict(dict);
			return (0);
		}
		ptr++;
	}
	len = ft_strlen(nbr);
	if (len > dict->thousands_size * 3)
	{
		ft_putstr("Dict Error\n");
		free_dict(dict);
		return (0);
	}
	return (1);
}

void	ft_move_start(char **start_ptr)
{
	if (**start_ptr == '+')
		(*start_ptr)++;
	while (**start_ptr == '0' && *(*start_ptr + 1) != '\0')
		(*start_ptr)++;
}

void	ft_show_result(int res)
{
	if (res == 0)
		ft_putstr("Error\n");
	if (res == -1)
		ft_putstr("Dict Error\n");
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*num;
	int		res;

	dict = 0;
	if (argc < 2 || argc > 3)
		return (return_err("Error\n"));
	if (argc == 2)
		res = read_dict(&dict, "numbers.dict");
	else
		res = read_dict(&dict, argv[1]);
	num = argv[argc - 1];
	if (!check_dict(dict) || !res)
	{
		free_dict(dict);
		return (return_err("Dict Error\n"));
	}
	ft_move_start(&num);
	if (!check_num(dict, num))
		return (1);
	ft_show_result(ft_print_num(dict, num));
	free_dict(dict);
	return (0);
}
