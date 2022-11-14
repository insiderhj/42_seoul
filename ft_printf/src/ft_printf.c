/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:56:33 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/14 22:01:02 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(const char *format, va_list ap)
{
	int			res;
	t_print_opt	opt;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			opt = ft_parse_opt(&format);
			res += ft_print_conversion(opt, ap);
		}
		else
		{
			ft_putchar(*format);
			format++;
			res++;
		}
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, format);
	res = ft_parse(format, ap);
	va_end(ap);
	return (res);
}
