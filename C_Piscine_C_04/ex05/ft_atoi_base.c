/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:41:46 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/30 00:46:25 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int	ft_valid_base(char *base)
{
	char	*ptr;

	if (ft_strlen(base) < 2)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-'
			|| *base == ' ' || *base == '\t' || *base == '\r'
			|| *base == '\n' || *base == '\v' || *base == '\f')
			return (0);
		ptr = base + 1;
		while (*ptr)
		{
			if (*base == *ptr)
				return (0);
			ptr++;
		}
		base++;
	}
	return (1);
}

int	ft_get_pos(char *base, char c)
{
	int	idx;

	idx = 0;
	while (*base)
	{
		if (*base == c)
			return (idx);
		idx++;
		base++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	neg;
	int	res;

	if (!ft_valid_base(base))
		return (0);
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
	while (str != '\0' && ft_get_pos(base, *str) != -1)
	{
		if (neg)
			res = res * ft_strlen(base) - ft_get_pos(base, *str);
		else
			res = res * ft_strlen(base) + ft_get_pos(base, *str);
		str++;
	}
	return (res);
}
