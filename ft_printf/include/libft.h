/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:49:37 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/14 21:37:07 by heejikim         ###   ########.fr       */
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
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putnchar(char c, int len);
void	ft_putnnbr(long long n, int len);
void	ft_putnhex(unsigned long long n, int len, int uppercase);
void	ft_putnstr(char *s, int len);
char	*ft_strchr(const char *s, int c);

#endif