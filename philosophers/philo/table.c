/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:01:28 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/08 03:36:18 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philosophers.h"

t_table	*create_table(void)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	memset(table, 0, sizeof(t_table));
	table->must_eat = -1;
	table->turn = EVEN;
	pthread_mutex_init(&table->global_mutex, NULL);
	pthread_mutex_init(&table->fork_mutex, NULL);
	pthread_mutex_init(&table->eat_mutex, NULL);
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
		pthread_mutex_init(&table->philo[i].ready, NULL);
		table->forks[i] = AVAILABLE;
	}
	return (1);
}

int	check_table(t_table *table)
{
	struct timeval	cur_time;
	int				ms;
	int				res;

	gettimeofday(&cur_time, NULL);
	ms = get_ms(table->start_time);
	pthread_mutex_lock(&table->eat_mutex);
	check_turn(table);
	res = check_philos(table, ms);
	if (res == 0)
	{
		pthread_mutex_lock(&table->global_mutex);
		table->done = 1;
		pthread_mutex_unlock(&table->global_mutex);
	}
	pthread_mutex_unlock(&table->eat_mutex);
	return (res);
}

void	check_turn(t_table *table)
{
	int		half_size;

	half_size = table->size / 2;
	if (table->turn == EVEN && table->even_cnt == half_size)
	{
		table->even_cnt = 0;
		table->turn = ODD;
	}
	else if (table->turn == ODD && table->odd_cnt == half_size)
	{
		table->odd_cnt = 0;
		table->turn = EVEN;
		if (table->size % 2)
			table->turn = LAST;
	}
	else if (table->turn == LAST && table->last_eaten)
	{
		table->last_eaten = 0;
		table->turn = EVEN;
	}
}

int	check_philos(t_table *table, int ms)
{
	int				i;
	int				all_eaten;

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
