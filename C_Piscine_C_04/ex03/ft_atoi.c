/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:29:15 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/29 21:06:19 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	neg;
	int	res;

	neg = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = !neg;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (neg)
			res = res * 10 - (*str - '0');
		else
			res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}
