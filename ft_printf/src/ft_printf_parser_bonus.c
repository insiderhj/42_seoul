/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:34 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/02 21:29:20 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_print_opt	ft_parse_opt(const char **format)
{
	t_print_opt	res;

	res.type = NONE;
	res.flag_minus = 0;
	res.flag_zero = 0;
	res.flag_precision = 0;
	res.flag_sharp = 0;
	res.flag_space = 0;
	res.flag_plus = 0;
	res.width = 0;
	res.precision = 0;
	ft_parse_flag(format, &res);
	ft_parse_width(format, &res);
	ft_parse_precision(format, &res);
	ft_parse_type(format, &res);
	return (res);
}

void	ft_parse_flag(const char **format, t_print_opt *opt)
{
	while (ft_isflag(**format))
	{
		if (**format == '-')
			opt->flag_minus = 1;
		else if (**format == '0')
			opt->flag_zero = 1;
		else if (**format == '#')
			opt->flag_sharp = 1;
		else if (**format == ' ')
			opt->flag_space = 1;
		else if (**format == '+')
			opt->flag_plus = 1;
		(*format)++;
	}
}

void	ft_parse_width(const char **format, t_print_opt *opt)
{
	while (ft_isdigit(**format))
	{
		opt->width = opt->width * 10 + **format - '0';
		(*format)++;
	}
}

void	ft_parse_precision(const char **format, t_print_opt *opt)
{
	if (**format == '.')
	{
		opt->flag_zero = 0;
		opt->flag_precision = 1;
		(*format)++;
	}
	while (ft_isdigit(**format))
	{
		opt->precision = opt->precision * 10 + **format - '0';
		(*format)++;
	}
}

void	ft_parse_type(const char **format, t_print_opt *opt)
{
	if (ft_istype(**format))
	{
		if (**format == 'c')
			opt->type = CHARACTER;
		else if (**format == 's')
			opt->type = STRING;
		else if (**format == 'p')
			opt->type = POINTER;
		else if (**format == 'd' || **format == 'i')
			opt->type = DECIMAL;
		else if (**format == 'u')
			opt->type = UNSIGNED_DECIMAL;
		else if (**format == 'x')
			opt->type = HEX_LOWER;
		else if (**format == 'X')
			opt->type = HEX_UPPER;
		else if (**format == '%')
			opt->type = PERCENT;
		(*format)++;
	}
}
