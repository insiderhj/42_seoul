/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:49:37 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/30 22:30:20 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

size_t	ft_nbrlen(long long n);
size_t	ft_hexlen(unsigned long long n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_putnbr(long long n);
int		ft_puthex(unsigned long long n, int uppercase);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnchar(char c, int len);
int		ft_putnstr(char *s, int len);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
char	*ft_itoa(size_t n);

#endif