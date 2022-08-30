/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:05:26 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/30 16:55:30 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr;
	char	*src;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		ptr = str;
		src = to_find;
		while (*src && *ptr == *src)
		{
			src++;
			ptr++;
		}
		if (!*src)
			return (str);
		str++;
	}
	return (0);
}
