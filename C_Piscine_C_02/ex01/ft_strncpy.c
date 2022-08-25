/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:57:14 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/24 23:04:57 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[n] = src[n];
		i++;
	}
	while (i < n)
	{
		dest[n] = '\0';
		i++;
	}
	return (dest);
}
