/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:05:22 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 03:53:00 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush02.h"

int	ft_inc_thousands(t_dict *dict, int zeros)
{
	char	**new;
	int		i;
	int		idx;

	idx = zeros / 3;
	new = (char **)malloc(sizeof(char *) * (zeros / 3 + 1));
	if (!new)
		return (0);
	i = 0;
	while (i < zeros / 3)
	{
		if (i < dict->thousands_size)
			new[i] = dict->thousands[i];
		else
			new[i] = 0;
		i++;
	}
	free(dict->thousands);
	dict->thousands_size = zeros / 3 + 1;
	dict->thousands = new;
	i = 0;
	return (1);
}

int	ft_put_dict(char **position, char *str)
{
	if (!position)
	{
		free(str);
		return (1);
	}
	if (*position)
		return (ft_free(&str));
	*position = str;
	return (1);
}
