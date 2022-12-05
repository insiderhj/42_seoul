/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:01:28 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/05 11:59:17 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

t_table	*create_table(void)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->size = 0;
	table->ttd = 0;
	table->tte = 0;
	table->tts = 0;
	table->must_eat = -1;
	table->done = 0;
	table->philo = NULL;
	table->forks = NULL;
	pthread_mutex_init(&table->global_mutex, NULL);
	pthread_mutex_init(&table->fork_mutex, NULL);
	return (table);
}

int	init_table(t_table *table, int argc, char **argv)
{
	int	i;

	table->size = ft_atoi(argv[1]);
	table->ttd = ft_atoi(argv[2]);
	table->tte = ft_atoi(argv[3]);
	table->tts = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	table->philo = malloc(sizeof(t_philo) * table->size);
	table->forks = malloc(sizeof(t_stat) * table->size);
	if (!table->philo || !table->forks)
		return (0);
	i = -1;
	while (++i < table->size)
	{
		table->philo[i].table = table;
		table->philo[i].last_eat = 0;
		table->philo[i].idx = i;
		table->philo[i].eaten = 0;
		table->forks[i] = AVAILABLE;
	}
	return (1);
}

int	check_table(t_table *table)
{
	struct timeval	cur_time;
	int				ms;
	int				i;
	int				all_eaten;

	gettimeofday(&cur_time, NULL);
	ms = get_ms(table->start_time);
	all_eaten = 1;
	i = 0;
	while (i < table->size)
	{
		if (table->philo[i].last_eat + table->ttd < ms)
		{
			print_state(table, i, "died", 1);
			return (0);
		}
		if (table->must_eat < 0
			|| (table->must_eat >= 0 && all_eaten == 1
				&& table->philo[i].eaten < table->must_eat))
			all_eaten = 0;
		i++;
	}
	return (!all_eaten);
}

int	free_table(t_table *table)
{
	if (table)
	{
		table->done = 1;
		if (table->philo)
			join_all(table);
		free(table->philo);
		if (table->forks)
			free(table->forks);
		pthread_mutex_destroy(&table->fork_mutex);
		pthread_mutex_destroy(&table->global_mutex);
		free(table);
	}
	return (0);
}
