/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:36:56 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/27 05:43:17 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf.h"
#include "minitalk.h"

t_client_stat	g_stat;

int	ft_isnum(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	send_bit(int signo, siginfo_t *info, void *s)
{
	(void)info;
	(void)s;
	if (signo == SIGUSR2)
		exit(1);
	if (*g_stat.str & (1 << (7 - g_stat.bits)))
		kill(g_stat.ppid, SIGUSR2);
	else
		kill(g_stat.ppid, SIGUSR1);
	g_stat.bits++;
	if (g_stat.bits == 8)
	{
		g_stat.str++;
		g_stat.bits = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	if (argc != 3 || !ft_isnum(argv[1]))
	{
		ft_printf("usage: client [PID] [string]\n");
		return (1);
	}
	g_stat.ppid = ft_atoi(argv[1]);
	g_stat.str = argv[2];
	g_stat.bits = 0;
	sig.sa_sigaction = send_bit;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	send_bit(SIGUSR1, NULL, NULL);
	while (1)
		pause();
	return (0);
}
