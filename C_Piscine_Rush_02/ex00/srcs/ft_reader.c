/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:35:21 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 21:19:25 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

char	**find_pos_thousands(t_dict *dict, char *num)
{
	int	i;
	int	zeros;

	i = 0;
	zeros = 0;
	while (num[i] == 0)
		i++;
	if (num[i++] != '1')
		return (0);
	while (!is_space(num[i]) && num[i] != ':')
	{
		if (num[i] != '0')
			return (0);
		zeros++;
		i++;
	}
	if (zeros % 3)
		return (0);
	if (zeros > dict->thousands_size * 3
		&& !ft_inc_thousands(dict, zeros))
		return (0);
	return (dict->thousands + (zeros / 3));
}

char	**find_position(t_dict *dict, char *num, int len)
{
	int		zeros;
	int		int_num;
	int		i;

	i = -1;
	zeros = 0;
	while (num[++i] == '0')
		zeros++;
	len -= zeros;
	if (len > 3)
		return (find_pos_thousands(dict, num));
	int_num = ft_atoi(num);
	if (int_num == -1)
		return (0);
	if (int_num >= 0 && int_num <= 9)
		return (dict->ones + int_num);
	else if (int_num >= 10 && int_num <= 19)
		return (dict->teens + (int_num - 10));
	else if (int_num >= 20 && int_num <= 90)
		return (dict->tens + (int_num / 10));
	else
		return (&(dict->hundred));
}

char	*parse_str(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		if (buf[i] < 32 || buf[i] > 126)
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (ft_strdup(buf, i));
}

int	input_dict(t_dict *dict, char *buf)
{
	int		i;
	int		num;
	char	**position;
	char	*str;

	i = 0;
	num = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	position = find_position(dict, buf, i);
	while (is_space(buf[i]))
		i++;
	if (buf[i++] != ':')
		return (0);
	while (is_space(buf[i]))
		i++;
	str = parse_str(buf + i);
	if (!str)
		return (0);
	return (ft_put_dict(position, str));
}

int	read_file(int fd, t_dict *dict)
{
	char	*buf;
	int		len;
	char	c;

	len = 0;
	buf = 0;
	while (read(fd, &c, 1))
	{
		if (!ft_add_buf(&buf, c))
			return (0);
		if (c == '\n')
		{
			if (len && !input_dict(dict, buf))
				return (ft_free(&buf));
			len = 0;
			ft_free(&buf);
		}
		else
			len++;
	}
	if (buf)
		return (ft_free(&buf));
	return (1);
}
