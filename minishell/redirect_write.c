/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:58:02 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/26 16:06:44 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_file_access(char *filename)
{
	char	*tmp;
	char	*dir;

	tmp = ft_strrchr(filename, '/');
	if (tmp != NULL)
	{
		dir = malloc(sizeof(char) * (tmp - filename + 1));
		if (dir == NULL)
			print_error(ERR_MALLOC, NULL);
		ft_strlcpy(dir, filename, tmp - filename + 1);
		if (access(dir, F_OK) == -1)
		{
			print_error(ERR_NO_FILE, filename);
			free(dir);
			return (-1);
		}
		free(dir);
	}
	return (0);
}

int	write_redirect(char *filename, int append_flag)
{
	int	fd;

	if (check_file_access(filename) < 0)
		return (-1);
	fd = open(filename, O_RDWR | O_CREAT | append_flag, 644);
	if (fd < 0)
	{
		print_error(ERR_AUTH_FAIL, filename);
		return (-1);
	}
	return (fd);
}
