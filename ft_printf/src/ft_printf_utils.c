/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:47:39 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/14 22:08:21 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char c)
{
	return (c && ft_strchr("-0# +", c) != NULL);
}

int	ft_istype(char c)
{
	return (c && ft_strchr("cspdiuxX%%", c) != NULL);
}

int	ft_count_prefix(t_print_opt opt, t_print_data data)
{
	if (opt.type == POINTER
		|| ((opt.type == HEX_LOWER || opt.type == HEX_UPPER) && opt.flag_sharp
			&& data.n != 0))
		return (2);
	if (opt.type == DECIMAL
		&& (data.n < 0 || opt.flag_plus || opt.flag_space))
		return (1);
	return (0);
}

int	ft_put_prefix(t_print_opt opt, t_print_data data)
{
	if (opt.type == POINTER
		|| (opt.type == HEX_LOWER && opt.flag_sharp && data.n != 0))
		return (ft_putstr("0x"));
	if (opt.type == HEX_UPPER && opt.flag_sharp && data.n != 0)
		return (ft_putstr("0X"));
	if (opt.type == DECIMAL)
	{
		if (data.n < 0)
			return (ft_putchar('-'));
		if (opt.flag_plus)
			return (ft_putchar('+'));
		if (opt.flag_space)
			return (ft_putchar(' '));
	}
	return (0);
}

void	ft_byte_cast(t_print_data *data)
{
	if (data->len > 8)
		data->len = 8;
	data->n &= 0xffffffff;
}
