/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:31:03 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 02:15:18 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_puterr(char *cmd, char *op, char *err, char *info)
{
	ft_putstr(cmd);
	ft_putstr(": ");
	if (op)
	{
		ft_putstr(op);
		ft_putstr(": ");
	}
	ft_putstr(err);
	if (info)
	{
		ft_putstr(" -- ");
		ft_putstr(info);
	}
	ft_putchar('\n');
	return (1);
}
