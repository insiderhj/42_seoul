/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:16:36 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/14 22:08:30 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(t_print_opt opt, va_list ap)
{
	t_print_data	data;
	int				prefix_len;

	data = ft_get_data(opt, ap);
	prefix_len = ft_count_prefix(opt, data);
	if (!opt.flag_minus && !opt.flag_zero)
		ft_putnchar(' ', opt.width - data.len - prefix_len);
	ft_put_prefix(opt, data);
	if (!opt.flag_minus && opt.flag_zero)
		ft_putnchar('0', opt.width - data.len - prefix_len);
	ft_putdata(opt.type, data);
	if (opt.flag_minus)
		ft_putnchar(' ', opt.width - data.len - prefix_len);
	if (opt.width > data.len + prefix_len)
		return (opt.width);
	return (data.len + prefix_len);
}

t_print_data	ft_get_data(t_print_opt opt, va_list ap)
{
	t_print_data	data;

	if (opt.type == CHARACTER || opt.type == PERCENT)
	{
		if (opt.type == CHARACTER)
			data.c = va_arg(ap, int);
		else
			data.c = '%';
		data.len = 1;
	}
	else if (opt.type == STRING)
	{
		data.s = va_arg(ap, char *);
		if (data.s)
			data.len = ft_strlen(data.s);
		else
			data.len = 6;
		if (opt.flag_precision && opt.precision < data.len)
			data.len = opt.precision;
	}
	else if (opt.type != NONE)
		data = ft_get_data2(opt, ap);
	else
		data.len = 0;
	return (data);
}

t_print_data	ft_get_data2(t_print_opt opt, va_list ap)
{
	t_print_data	data;

	if (opt.type == DECIMAL || opt.type == UNSIGNED_DECIMAL)
	{
		if (opt.type == DECIMAL)
			data.n = va_arg(ap, int);
		else
			data.n = va_arg(ap, unsigned int);
		data.len = ft_nbrlen(data.n);
	}
	else if (opt.type == POINTER)
	{
		data.n = (long long)va_arg(ap, void *);
		data.len = ft_hexlen(data.n);
	}
	else
	{
		data.n = (long long)va_arg(ap, int);
		data.len = ft_hexlen(data.n);
		ft_byte_cast(&data);
	}
	if (opt.flag_precision && (opt.precision > data.len || data.n == 0))
		data.len = opt.precision;
	return (data);
}

void	ft_putdata(t_type type, t_print_data data)
{
	if (type == CHARACTER || type == PERCENT)
		ft_putchar(data.c);
	else if (type == STRING)
		ft_putnstr(data.s, data.len);
	else if (type == DECIMAL || type == UNSIGNED_DECIMAL)
		ft_putnnbr(data.n, data.len);
	else if (type == POINTER || type == HEX_LOWER || type == HEX_UPPER)
		ft_putnhex(data.n, data.len, type == HEX_UPPER);
}
