/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:59:04 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 18:02:26 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	cnt_dict_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}

int	check_if_zeros(char *nums)
{
	int	cnt_zero;
	int	i;

	cnt_zero = 0;
	i = 0;
	while (i < 3)
	{
		if (*nums == '0')
			cnt_zero++;
		nums++;
		i++;
	}
	if (cnt_zero == 3)
		return (1);
	return (0);
}

int	check_has_next(char **nums, int pos)
{
	while (nums[++pos])
	{
		if (nums[pos][0] != '0' || nums[pos][1] != '0' || nums[pos][2] != '0')
			return (1);
	}
	return (0);
}

int	check_printable(t_dict *dict, char **nums)
{
	int	len;
	int	i;

	i = 0;
	len = cnt_dict_nums(nums);
	while (len > 1)
	{
		if (check_if_zeros(nums[i]) == 0 && dict->thousands[len - 1] == 0)
			return (0);
		i++;
		len--;
	}
	return (1);
}
