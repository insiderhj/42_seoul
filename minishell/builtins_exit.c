/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:26:10 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/28 15:16:48 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_atoi(char *s)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + *s - '0';
		s++;
	}
	if (*s != '\0' && (*s < '0' || *s > '9'))
		return (-1);
	num *= sign;
	if (num > 255)
		num -= 256;
	while (num < 0)
		num += 256;
	return (num);
}

void	builtin_exit(t_token token)
{
	int	exit_code;

	exit_code = exit_atoi(token.argv[1]);
	if (exit_code < 0)
	{
		print_error(ERR_NUM_ARG_REQ, NULL);
		exit(255);
	}
	if (token.argc > 2)
	{
		print_error(ERR_TOO_MANY_ARGS, "exit");
		return ;
	}
	exit(exit_code);
}
