/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:31:03 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/06 02:38:46 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puterr(char *cmd, char *op, char *err)
{
	ft_putstr(cmd);
	ft_putstr(": ");
	ft_putstr(op);
	ft_putstr(": ");
	ft_putstr(err);
	ft_putchar('\n');
	return ;
}
