/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:00:23 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 05:25:31 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker_bonus.h"

int	checker(t_stack *stack)
{
	char	*str;
	size_t	len;
	int		err;

	err = 0;
	len = 0;
	str = NULL;
	str = ft_realloc(str, 1);
	if (!str)
		return (-1);
	while (read(0, str + len++, 1))
	{
		str = ft_realloc(str, len + 1);
		if (!str)
			return (-1);
		if (str[len - 1] == '\n')
		{
			flush(stack, &str, &err, &len);
			str = ft_realloc(str, 1);
			if (!str)
				return (-1);
		}
	}
	clear_buf(str, &err);
	return (err);
}

void	flush(t_stack *stack, char **str, int *err, size_t *len)
{
	if (*len == 0 || (*str)[*len - 1] != '\n')
	{
		*err = -1;
		free(*str);
		*str = NULL;
		*len = 0;
		return ;
	}
	*str = ft_realloc(*str, *len);
	if (!*str)
	{
		*err = -1;
		return ;
		*len = 0;
	}
	if (!do_op(stack, *str, 0))
		*err = -1;
	free(*str);
	*str = NULL;
	*len = 0;
}

void	clear_buf(char *str, int *err)
{
	if (!str)
		return ;
	if (*str)
		*err = -1;
	free(str);
}

char	*ft_realloc(char *old, size_t new_len)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(new_len);
	if (!res)
	{
		if (old)
			free(old);
		return (NULL);
	}
	if (old)
	{
		while (i < new_len - 1)
		{
			res[i] = old[i];
			i++;
		}
		free(old);
	}
	res[i] = '\0';
	return (res);
}

void	check_result(t_stack *stack)
{
	t_elem	*cur;

	if (stack->size_b > 0)
	{
		write(1, "KO\n", 3);
		return ;
	}
	cur = stack->ta->up;
	while (cur != stack->ta)
	{
		if (cur->val < cur->up->val)
		{
			write(1, "KO\n", 3);
			return ;
		}
		cur = cur->up;
	}
	write(1, "OK\n", 3);
}
