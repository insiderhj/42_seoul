/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:25:14 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/31 17:16:49 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_valid_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_to_base(char *str, int *i, int nbr, char *base);

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(src) + 1);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*temp;
	char	*res;
	int		i;

	if (!ft_valid_base(base_from) || !ft_valid_base(base_to))
		return (0);
	i = 0;
	temp = ft_to_base(0, &i, ft_atoi_base(nbr, base_from), base_to);
	res = ft_strdup(temp);
	free(temp);
	return (res);
}
