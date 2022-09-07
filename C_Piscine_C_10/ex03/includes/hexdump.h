/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:49:20 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 03:03:00 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

typedef struct buf
{
	unsigned int	pos;
	unsigned int	len;
	char			str[16];
	char			prev[16];
	int				skipped;
}	t_buf;

void	ft_init_buf(t_buf *buf);
void	ft_read_buf(int fd, t_buf *buf, int print_flag);
void	ft_print_leftover(t_buf buf, int print_flag);
void	ft_put_pos(unsigned int pos, int print_flag);

void	ft_put_dump(t_buf buf, int print_flag);
void	ft_dump_input(int print_flag);
void	ft_dump_file(int argc, char **argv, int print_flag);

#endif
