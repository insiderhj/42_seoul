/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:08:17 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 02:40:22 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct display_info
{
	int		pad;
	int		input_len;
}	t_display_info;

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_puterr(char *cmd, char *op, char *err, char *info);
long long	ft_getnum(char *str);

int			ft_tail_input(char *cmd, long long input_len);
int			ft_display_file(int argc, char *cmd,
				char *filename, t_display_info info);

#endif
