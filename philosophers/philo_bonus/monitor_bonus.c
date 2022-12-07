/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:06:47 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/08 03:44:46 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers_bonus.h"

void	*monitor_die(void *param)
{
	t_table	*table;
	int		i;

	table = param;
	sem_wait(table->die_monitor);
	i = 0;
	while (i < table->size)
	{
		sem_post(table->eat_monitor);
		i++;
	}
	return (NULL);
}

void	*monitor_eat(void *param)
{
	t_table	*table;
	int		i;

	table = param;
	i = 0;
	while (i < table->size)
	{
		sem_wait(table->eat_monitor);
		i++;
	}
	sem_post(table->die_monitor);
	return (NULL);
}

void	pass_sem(sem_t *src_sem, sem_t *dst_sem, int src_count, int dst_count)
{
	int	i;

	i = 0;
	while (i < src_count)
	{
		sem_wait(src_sem);
		i++;
	}
	i = 0;
	while (i < dst_count)
	{
		sem_post(dst_sem);
		i++;
	}
}

void	*monitor_order(void *param)
{
	t_table	*table;
	int		half_size;

	table = param;
	half_size = table->size / 2;
	while (1)
	{
		pass_sem(table->turn_sem, table->odd_sem, half_size, half_size);
		if (table->size % 2 == 1)
		{
			pass_sem(table->turn_sem, table->last_sem, half_size, 1);
			pass_sem(table->turn_sem, table->even_sem, 1, half_size);
		}
		else
			pass_sem(table->turn_sem, table->even_sem, half_size, half_size);
	}
}

void	*monitor_philo(void *param)
{
	t_info	*info;

	info = param;
	while (1)
	{
		pthread_mutex_lock(&info->philo->eat_mutex);
		if (info->philo->last_eat + info->table.ttd
			< get_ms(info->table.start_time))
			break ;
		pthread_mutex_unlock(&info->philo->eat_mutex);
	}
	pthread_mutex_unlock(&info->philo->eat_mutex);
	print_state(info->table, info->philo, "died", 1);
	sem_post(info->table.die_monitor);
	return (NULL);
}
