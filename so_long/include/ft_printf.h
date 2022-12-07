/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:55:52 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/27 02:31:47 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef enum e_type {
	CHARACTER,
	STRING,
	POINTER,
	DECIMAL,
	UNSIGNED_DECIMAL,
	HEX_LOWER,
	HEX_UPPER,
	PERCENT,
	NONE
}	t_type;

typedef struct print_opt {
	t_type	type;
	int		flag_minus;
	int		flag_zero;
	int		flag_precision;
	int		flag_sharp;
	int		flag_space;
	int		flag_plus;
	int		width;
	int		precision;
}	t_print_opt;

typedef struct print_data {
	int			len;
	char		c;
	char		*s;
	void		*p;
	long long	n;
}	t_print_data;

int				ft_isflag(char c);
int				ft_istype(char c);
int				ft_count_prefix(t_print_opt opt, t_print_data data);
int				ft_put_prefix(t_print_opt opt, t_print_data data);
void			ft_byte_cast(t_print_data *data);

t_print_opt		ft_parse_opt(const char **format);
void			ft_parse_flag(const char **format, t_print_opt *opt);
void			ft_parse_width(const char **format, t_print_opt *opt);
void			ft_parse_precision(const char **format, t_print_opt *opt);
void			ft_parse_type(const char **format, t_print_opt *opt);

int				ft_print_conversion(t_print_opt opt, va_list ap);
t_print_data	ft_get_data(t_print_opt opt, va_list ap);
t_print_data	ft_get_data2(t_print_opt opt, va_list ap);
int				ft_putdata(t_type type, t_print_data data);

int				ft_printf(const char *format, ...);

#endif
