/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:53:31 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/06 09:17:50 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"
#include "hexdump.h"

void	ft_dump_input(int print_flag)
{
	t_buf	buf;

	ft_init_buf(&buf);
	ft_read_buf(0, &buf, print_flag);
	ft_print_leftover(buf, print_flag);
}
