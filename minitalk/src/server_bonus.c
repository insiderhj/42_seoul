/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:13:04 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/27 04:36:32 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"
#include "minitalk.h"

int	realloc_str(void)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc(g_stat.len + 1);
	if (!temp)
	{
		if (g_stat.len)
			free(g_stat.str);
		return (0);
	}
	i = 0;
	while (i < g_stat.len)
	{
		temp[i] = g_stat.str[i];
		i++;
	}
	temp[i] = '\0';
	if (g_stat.len)
		free(g_stat.str);
	g_stat.str = temp;
	g_stat.len++;
	return (1);
}

void	get_sig(int signo, siginfo_t *info, void *s)
{
	(void)s;
	if (g_stat.bits == 0 && !realloc_str())
		exit(-1);
	if (signo == SIGUSR1)
		g_stat.str[g_stat.len - 1] <<= 1;
	else if (signo == SIGUSR2)
	{
		g_stat.str[g_stat.len - 1] <<= 1;
		g_stat.str[g_stat.len - 1] |= 1;
	}
	g_stat.bits++;
	if (g_stat.bits == 8)
	{
		g_stat.bits = 0;
		if (!g_stat.str[g_stat.len - 1])
		{
			write(1, g_stat.str, g_stat.len);
			write(1, "\n", 1);
			free(g_stat.str);
			g_stat.len = 0;
			kill(info->si_pid, SIGUSR2);
			return ;
		}
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("server pid: %d\n", getpid());
	g_stat.str = NULL;
	g_stat.bits = 0;
	sig.sa_sigaction = get_sig;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
