/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:56:33 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/17 03:49:58 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse(const char *format, va_list ap)
{
	int			res;
	int			temp;
	t_print_opt	opt;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			opt = ft_parse_opt(&format);
			temp = ft_print_conversion(opt, ap);
			if (temp == -1)
				return (-1);
			res += temp;
		}
		else
		{
			if (ft_putchar(*format) == -1)
				return (-1);
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
