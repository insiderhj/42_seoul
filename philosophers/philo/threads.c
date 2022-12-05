/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:05:34 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/03 07:05:49 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->size)
	{
		pthread_create(&table->philo[i].thread, NULL, create_philo,
			table->philo + i);
		i++;
	}
}

void	join_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->size)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}
