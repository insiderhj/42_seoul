/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insiderHJ <heejikim@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:49:37 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/15 12:14:36 by insiderHJ        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_nbrlen(long long n);
size_t	ft_hexlen(unsigned long long n);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_putnbr(long long n);
void	ft_puthex(unsigned long long n, int uppercase);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putnchar(char c, int len);
void	ft_putnstr(char *s, int len);
char	*ft_strchr(const char *s, int c);

#endif