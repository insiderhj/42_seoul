/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 01:37:45 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/26 21:59:30 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*ptr;
	int		up;

	ptr = str;
	up = 1;
	while (*ptr)
	{
		if ((*ptr >= 'a' && *ptr <= 'z')
			|| (*ptr >= 'A' && *ptr <= 'Z')
			|| (*ptr >= '0' && *ptr <= '9'))
		{
			if (up == 1 && *ptr >= 'a' && *ptr <= 'z')
				*ptr += 'A' - 'a';
			else if (up == 0 && *ptr >= 'A' && *ptr <= 'Z')
				*ptr += 'a' - 'A';
			up = 0;
		}
		else
			up = 1;
		ptr++;
	}
	return (str);
}
