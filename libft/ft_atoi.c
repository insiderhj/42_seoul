/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:40:10 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/11 16:03:52 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\r' || c == '\n'
		|| c == ' ' || c == '\f' || c == '\v');
}

long long	ft_calc_atoi(const char *str, int sign)
{
	long long	res;

	res = 0;
	if (sign == 1)
	{
		while (*str && *str >= '0' && *str <= '9')
		{
			res = res * 10 + (*str - '0');
			if (res < 0)
				return (-1);
			str++;
		}
		return (res);
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 - (*str - '0');
		if (res > 0)
			return (0);
		str++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int			sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (ft_calc_atoi(str, sign));
}
