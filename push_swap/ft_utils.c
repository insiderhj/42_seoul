/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:28:13 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 05:04:01 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + sign * (*str - '0');
		if ((sign == 1 && res < 0) || (sign == -1 && res > 0))
			return (res);
		str++;
	}
	return (res);
}

int	ft_check_num(const t_stack *stack, const char *str)
{
	int		is_num;
	int		res;
	size_t	i;

	is_num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		is_num = 1;
		i++;
	}
	res = ft_atoi(str);
	if (str[i]
		|| (str[0] == '-' && res > 0)
		|| (str[0] != '-' && res < 0)
		|| ft_find(stack->ta, res))
		return (0);
	return (is_num);
}

void	print_op(char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}
