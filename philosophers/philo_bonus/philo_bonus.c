/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:00:51 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/08 03:56:18 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers_bonus.h"

void	create_processes(t_table *table)
{
	int		i;
	pid_t	pid;
	t_philo	philo;

	i = 0;
	while (i < table->size)
	{
		pid = fork();
		if (pid == 0)
		{
			philo.idx = i;
			philo.last_eat = 0;
			philo.eaten = 0;
			create_philo(*table, philo);
		}
		else
			table->children[i] = pid;
		i++;
	}
	sem_post(table->global_sem);
}

void	create_philo(t_table table, t_philo philo)
{
	t_info		info;
	pthread_t	th;

	info.table = table;
	info.philo = &philo;
	pthread_mutex_init(&philo.eat_mutex, NULL);
	pthread_create(&th, NULL, monitor_philo, &info);
	sem_wait(table.global_sem);
	sem_post(table.global_sem);
	while (1)
	{
		if (table.size % 2 == 1 && philo.idx == table.size - 1)
			sem_wait(table.last_sem);
		else if (philo.idx % 2 == 0)
			sem_wait(table.even_sem);
		else
			sem_wait(table.odd_sem);
		philo_loop(table, &philo);
	}
	exit(0);
}

void	philo_loop(t_table table, t_philo *philo)
{
	sem_wait(table.forks);
	print_state(table, philo, "has taken a fork", 0);
	sem_wait(table.forks);
	print_state(table, philo, "has taken a fork", 0);
	philo->last_eat = print_state(table, philo, "is eating", 0);
	usleep(table.tte * 1000);
	philo->eaten++;
	sem_post(table.turn_sem);
	if (table.must_eat != -1 && philo->eaten >= table.must_eat)
		sem_post(table.eat_monitor);
	sem_post(table.forks);
	sem_post(table.forks);
	print_state(table, philo, "is sleeping", 0);
	usleep(table.tts * 1000);
	print_state(table, philo, "is thinking", 0);
}
