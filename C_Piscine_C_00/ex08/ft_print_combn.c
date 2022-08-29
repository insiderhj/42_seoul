/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 02:32:34 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/25 14:53:58 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int len, char *str, char max)
{
	char	cur;

	cur = str[len - 1] + 1;
	while (cur <= max)
	{
		str[len] = cur;
		if (max == '9')
		{
			write(1, str, len + 1);
			if (str[0] != '9' - len)
				write(1, ", ", 2);
		}
		else
			print_num(len + 1, str, max + 1);
		cur++;
	}
}

void	ft_print_combn(int n)
{
	char	str[11];
	char	max;

	str[0] = '0';
	max = '9' - n + 1;
	while (str[0] <= max)
	{
		if (max == '9')
		{
			write(1, str, 1);
			if (str[0] != '9')
				write(1, ", ", 2);
		}
		else
			print_num(1, str, max + 1);
		str[0]++;
	}
}
