/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:00:51 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/08 04:06:05 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "philosophers.h"

void	*create_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_unlock(&philo->ready);
	pthread_mutex_lock(&philo->table->global_mutex);
	pthread_mutex_unlock(&philo->table->global_mutex);
	while (1)
	{
		check_done(philo->table);
		wait_turn(philo->table, philo);
		take_fork(philo);
		pthread_mutex_lock(&philo->table->eat_mutex);
		philo->last_eat = print_state(philo->table, philo->idx, "is eating", 0);
		pthread_mutex_unlock(&philo->table->eat_mutex);
		ft_sleep(philo->table->tte);
		pthread_mutex_lock(&philo->table->eat_mutex);
		philo->eaten++;
		increase_cnt(philo->table, philo->idx);
		pthread_mutex_unlock(&philo->table->eat_mutex);
		put_fork(philo->table, philo);
		print_state(philo->table, philo->idx, "is sleeping", 0);
		ft_sleep(philo->table->tts);
		print_state(philo->table, philo->idx, "is thinking", 0);
	}
	return (NULL);
}

void	wait_turn(t_table *table, t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&table->eat_mutex);
		if (table->size % 2 == 1 && philo->idx == table->size - 1)
		{
			if (table->turn == LAST)
				break ;
		}
		else if (philo->idx % 2 == 0)
		{
			if (table->turn == EVEN)
				break ;
		}
		else
		{
			if (table->turn == ODD)
				break ;
		}
		pthread_mutex_unlock(&table->eat_mutex);
	}
	pthread_mutex_unlock(&table->eat_mutex);
}

void	take_fork(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->idx;
	right = philo->idx + 1;
	if (right >= philo->table->size)
		right = 0;
	pick_fork(philo->table, left);
	print_state(philo->table, philo->idx, "has taken a fork", 0);
	while (philo->table->size == 1)
	{
		pthread_mutex_lock(&philo->table->global_mutex);
		if (philo->table->done)
		{
			pthread_mutex_unlock(&philo->table->global_mutex);
			exit(0);
		}
		pthread_mutex_unlock(&philo->table->global_mutex);
	}
	pick_fork(philo->table, right);
	print_state(philo->table, philo->idx, "has taken a fork", 0);
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
