/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:46:34 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/18 23:58:37 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	remove_node(t_save **root, int fd)
{
	t_save	*prev;
	t_save	*cur;

	prev = NULL;
	cur = *root;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (!prev)
				*root = cur->next;
			else
				prev->next = cur->next;
			free(cur->buf);
			free(cur);
			return (0);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return (0);
}

t_save	*ft_read(t_save **root, t_save *save)
{
	if (!save->sz)
		save->sz = read(save->fd, save->buf, BUFFER_SIZE);
	if (save->sz == -1)
	{
		remove_node(root, save->fd);
		return (NULL);
	}
	return (save);
}

int	ft_strjoin(t_save **root, char **dest, t_save *save, size_t *len)
{
	ssize_t	i;

	if (save->sz == 0)
		return (remove_node(root, save->fd));
	i = 0;
	while (i < save->sz)
	{
		if (save->buf[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	*dest = ft_realloc(*dest, *len + 1, *len + i + 1);
	if (!*dest)
		return (remove_node(root, save->fd));
	ft_strlcpy(*dest + *len, save->buf, i + 1);
	ft_strlcpy(save->buf, save->buf + i, BUFFER_SIZE - i + 1);
	*len += i;
	save->sz -= i;
	return ((*dest)[*len - 1] != '\n');
}

char	*get_next_line(int fd)
{
	static t_save	*root;
	char			*res;
	t_save			*save;
	size_t			len;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	save = find_node(&root, fd);
	if (!save)
		return (NULL);
	len = 0;
	res = NULL;
	if (!ft_read(&root, save))
		return (NULL);
	while (ft_strjoin(&root, &res, save, &len))
	{
		if (!ft_read(&root, save))
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}
