/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:59:02 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 21:20:43 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush02.h"

int	print_full_num(t_dict *dict, char **nums)
{
	int	has_next;
	int	len;
	int	i;

	len = cnt_dict_nums(nums) + 1;
	if (len == 2 && check_if_zeros(nums[0]))
	{
		ft_print_str(dict->ones[0], 0);
		ft_putchar('\n');
		return (1);
	}
	i = 0;
	while (--len > 0)
	{
		if (check_if_zeros(nums[i]) == 0)
		{
			has_next = check_has_next(nums, i);
			ft_print_unit(dict, nums[i], len, has_next);
			if (len > 1)
				ft_print_str(dict->thousands[len - 1], has_next);
		}
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int	ft_print_num(t_dict *dict, char *input)
{
	char	**nums;
	int		i;

	nums = ft_split(input);
	if (!nums)
		return (0);
	if (!check_printable(dict, nums))
	{
		i = 0;
		while (nums[i])
			free(nums[i++]);
		free(nums);
		return (-1);
	}
	print_full_num(dict, nums);
	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
	return (1);
}
