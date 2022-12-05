/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:02:37 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/05 10:58:28 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers_bonus.h"

int	ft_atoi(const char *s)
{
	int	res;

	if (*s == '-')
		return (-1);
	if (*s == '+')
		s++;
	res = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		res = res * 10 + *s - '0';
		if (res < 0)
			return (-1);
		s++;
	}
	return (res);
}

int	get_ms(struct timeval start_time)
{
	struct timeval	cur_time;
	long			sec;
	int				usec;
	int				res;

	gettimeofday(&cur_time, NULL);
	sec = cur_time.tv_sec - start_time.tv_sec;
	usec = cur_time.tv_usec - start_time.tv_usec;
	res = usec / 1000;
	res += sec * 1000;
	return (res);
}

int	print_state(t_table table, t_philo *philo, char *str, int die)
{
	int	ms;

	sem_wait(table.global_sem);
	ms = get_ms(table.start_time);
	printf("%d %d %s\n", ms, philo->idx + 1, str);
	if (!die)
		sem_post(table.global_sem);
	return (ms);
}

sem_t	*init_sem(char *name, int val)
{
	sem_t	*res;

	res = sem_open(name, O_CREAT | O_EXCL, 0644, val);
	if (res != SEM_FAILED)
		return (res);
	sem_unlink(name);
	return (init_sem(name, val));
}
