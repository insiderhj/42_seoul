/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:04:12 by heejikim          #+#    #+#             */
/*   Updated: 2022/08/28 12:02:16 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_addr(unsigned long long addr, int len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (len > 1)
		ft_print_addr(addr / 0x10, len - 1);
	write(1, hex + addr % 0x10, 1);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, hex + c / 0x10, 1);
	write(1, hex + c % 0x10, 1);
}

void	ft_print_bytes(char *ptr, int count)
{
	int	idx;

	idx = 0;
	while (idx < count)
	{
		ft_print_hex(*ptr);
		if (idx % 2)
			write(1, " ", 1);
		ptr++;
		idx++;
	}
	while (count < 0x10)
	{
		write(1, "  ", 2);
		if (count % 2)
			write(1, " ", 1);
		count++;
	}	
}

void	ft_putstr(char *str, int len)
{
	while (len)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
			write(1, ".", 1);
		str++;
		len--;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*ptr;
	int		n;

	ptr = addr;
	n = 0;
	while (size)
	{
		if (size >= 0x10)
			n = 0x10;
		else
			n = size;
		ft_print_addr((unsigned long long)ptr, 16);
		write(1, ": ", 2);
		ft_print_bytes(ptr, n);
		ft_putstr(ptr, n);
		write(1, "\n", 1);
		ptr += 0x10;
		size -= n;
	}
	return (addr);
}
