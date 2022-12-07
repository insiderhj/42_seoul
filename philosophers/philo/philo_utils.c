/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:02:37 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/07 20:01:28 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"

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

int	print_state(t_table *table, int idx, char *str, int done)
{
	int	ms;

	pthread_mutex_lock(&table->global_mutex);
	ms = get_ms(table->start_time);
	if (!table->done)
		printf("%d %d %s\n", ms, idx + 1, str);
	if (done)
		table->done = 1;
	pthread_mutex_unlock(&table->global_mutex);
	return (ms);
}
