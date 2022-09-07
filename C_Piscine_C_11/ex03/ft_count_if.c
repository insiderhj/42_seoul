/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:26:42 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 23:28:54 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f) (char*))
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			res++;
		i++;
	}
	return (res);
}
