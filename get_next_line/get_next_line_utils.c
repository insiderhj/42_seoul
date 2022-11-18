/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:44:06 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/17 11:12:22 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_save	*create_node(int fd)
{
	t_save	*res;
	size_t	i;

	res = malloc(sizeof(t_save));
	if (!res)
		return (NULL);
	res->buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!res->buf)
	{
		free(res);
		return (NULL);
	}
	i = 0;
	while (i < BUFFER_SIZE)
	{
		res->buf[i] = '\0';
		i++;
	}
	res->fd = fd;
	res->sz = 0;
	res->eof = 0;
	res->next = NULL;
	return (res);
}

t_save	*find_node(t_save **root, int fd)
{
	t_save			*node;
	t_save			*prev;

	if (!*root)
	{
		*root = create_node(fd);
		return (*root);
	}
	node = *root;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		prev = node;
		node = node->next;
	}
	prev->next = create_node(fd);
	return (prev->next);
}

void	ft_strlcpy(char *dst, char *src, size_t len)
{
	size_t	i;

	if (dst == src || len == 0)
		return ;
	i = 0;
	while (i + 1 < len)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
}

char	*ft_realloc(char *str, size_t before_len, size_t after_len)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * after_len);
	if (!new_str)
	{
		if (str)
			free(str);
		return (NULL);
	}
	if (str)
	{
		ft_strlcpy(new_str, str, before_len);
		free(str);
	}
	return (new_str);
}
