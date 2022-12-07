/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:05:34 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/08 03:29:42 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->size)
	{
		pthread_mutex_lock(&table->philo[i].ready);
		pthread_create(&table->philo[i].thread, NULL, create_philo,
			table->philo + i);
		i++;
	}
	i = 0;
	while (i < table->size)
	{
		pthread_mutex_lock(&table->philo[i].ready);
		pthread_mutex_unlock(&table->philo[i].ready);
		i++;
	}
}

void	check_done(t_table *table)
{
	pthread_mutex_lock(&table->global_mutex);
	if (table->done)
	{
		pthread_mutex_unlock(&table->global_mutex);
		exit(0);
	}
	pthread_mutex_unlock(&table->global_mutex);
}

int	free_table(t_table *table)
{
	int	i;

	if (table)
	{
		i = 0;
		while (i < table->size)
		{
			pthread_mutex_destroy(&table->philo[i].ready);
			pthread_join(table->philo[i].thread, NULL);
			i++;
		}
		free(table->philo);
		if (table->forks)
			free(table->forks);
		free(table);
	}
	return (0);
}
