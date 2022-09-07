/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:33:42 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/07 23:52:39 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	int	i;
	int	dir;

	if (length < 2)
		return (1);
	i = 0;
	dir = 0;
	while (i < length - 1)
	{
		if (dir == 0)
			dir = f(tab[i], tab[i + 1]);
		if (f(tab[i], tab[i + 1]) > 0)
		{
			if (dir < 0)
				return (0);
		}
		else if (f(tab[i], tab[i + 1]) < 0)
		{
			if (dir > 0)
				return (0);
		}
		i++;
	}
	return (1);
}
