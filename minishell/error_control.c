/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:26:17 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/29 10:09:36 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(t_error err, char *s)
{
	if (err == ERR_NOT_ENOUGH_ARGS)
	{
		printf("minishell: %s: not enough arguments\n", s);
		exit(1);
	}
	else if (err == ERR_TOO_MANY_ARGS)
	{
		printf("minishell: %s: too many arguments\n", s);
	}
	else if (err == ERR_INVALID_PARAM)
	{
		printf("minishell: %s: : not a valid identifier\n", s);
	}
	else if (err == ERR_NUM_ARG_REQ)
	{
		printf("minishell: %s: numeric argument required\n", s);
		exit(255);
	}
	else if (err == ERR_NO_FILE)
	{
		printf("minishell: %s: No such file or directory\n", s);
		exit(1);
	}
	else if (err == ERR_AUTH_FAIL)
	{
		printf("minishell: %s: Permission denied\n", s);
		exit(1);
	}
	else if (err == ERR_PARSE)
	{
		printf("minishell: parse error near \'\\n\'\n");
		exit(1);
	}
	else if (err == ERR_NO_CMD)
	{
		printf("minishell: %s: command not found\n", s);
		exit(1);
	}
	else
	{
		perror(s);
		exit(1);
	}
}
