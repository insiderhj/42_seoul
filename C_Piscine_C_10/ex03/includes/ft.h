/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:08:17 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 03:01:32 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puthex(unsigned int n, int len);
void	ft_puterr(char *cmd, char *op, char *err, char *info);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

#endif
