/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:00:51 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/05 12:00:12 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"

void	*create_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->table->global_mutex);
	pthread_mutex_unlock(&philo->table->global_mutex);
	while (!philo->table->done)
	{
		while (!is_turn(philo->table, philo) && !philo->table->done)
			;
		if (philo->table->done)
			return (NULL);
		take_fork(philo);
		philo->last_eat = print_state(philo->table, philo->idx, "is eating", 0);
		philo->eaten++;
		usleep(philo->table->tte * 1000);
		put_fork(philo->table, philo);
		print_state(philo->table, philo->idx, "is sleeping", 0);
		usleep(philo->table->tts * 1000);
		print_state(philo->table, philo->idx, "is thinking", 0);
	}
	return (NULL);
}

int	is_turn(t_table *table, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->idx - 1;
	right = philo->idx + 1;
	if (left < 0)
		left = table->size - 1;
	if (right >= table->size)
		right = 0;
	if (philo->idx == table->size - 1)
		return (table->philo[left].eaten >= philo->eaten);
	else if (philo->idx % 2 == 0)
		return (table->philo[left].eaten >= philo->eaten
			&& table->philo[right].eaten >= philo->eaten);
	else
		return (table->philo[left].eaten >= philo->eaten + 1);
}

void	take_fork(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->idx;
	right = philo->idx + 1;
	if (right >= philo->table->size)
		right = 0;
	if (philo->idx % 2 == 0)
	{
		pick_fork(philo->table, right);
		print_state(philo->table, philo->idx, "has taken a fork", 0);
		pick_fork(philo->table, left);
		print_state(philo->table, philo->idx, "has taken a fork", 0);
	}
	else
	{
		pick_fork(philo->table, left);
		print_state(philo->table, philo->idx, "has taken a fork", 0);
		pick_fork(philo->table, right);
		print_state(philo->table, philo->idx, "has taken a fork", 0);
	}
}

void	pick_fork(t_table *table, int idx)
{
	int	done;

	done = 0;
	while (1)
	{
		pthread_mutex_lock(&table->fork_mutex);
		if (table->forks[idx] == AVAILABLE)
		{
			table->forks[idx] = USING;
			done = 1;
		}
		pthread_mutex_unlock(&table->fork_mutex);
		if (done)
			break ;
		usleep(100);
	}
}

void	put_fork(t_table *table, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->idx;
	right = philo->idx + 1;
	if (right >= philo->table->size)
		right = 0;
	pthread_mutex_lock(&table->fork_mutex);
	table->forks[left] = AVAILABLE;
	table->forks[right] = AVAILABLE;
	pthread_mutex_unlock(&table->fork_mutex);
}
