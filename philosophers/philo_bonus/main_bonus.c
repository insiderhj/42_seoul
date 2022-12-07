/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:45:20 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/08 01:48:50 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "philosophers_bonus.h"

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6 || ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0
		|| (argc == 6 && ft_atoi(argv[5]) <= 0))
		return (0);
	return (1);
}

t_table	init_table(int argc, char **argv)
{
	t_table	table;

	table.size = ft_atoi(argv[1]);
	table.ttd = ft_atoi(argv[2]);
	table.tte = ft_atoi(argv[3]);
	table.tts = ft_atoi(argv[4]);
	if (argc == 6)
		table.must_eat = ft_atoi(argv[5]);
	else
		table.must_eat = -1;
	gettimeofday(&table.start_time, NULL);
	table.global_sem = init_sem("global_sem", 0);
	table.forks = init_sem("forks", table.size);
	table.even_sem = init_sem("even_sem", table.size / 2);
	table.odd_sem = init_sem("odd_sem", 0);
	table.last_sem = init_sem("last_sem", 0);
	table.turn_sem = init_sem("turn_sem", 0);
	table.eat_monitor = init_sem("eat_monitor", 0);
	table.die_monitor = init_sem("die_monitor", 0);
	return (table);
}

void	killall(int size, pid_t *children)
{
	int	i;

	if (!children)
		return ;
	i = 0;
	while (i < size)
	{
		kill(children[i], SIGKILL);
		i++;
	}
	free(children);
}

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	eat_mntr;
	pthread_t	die_mntr;
	pthread_t	order_mntr;

	if (!check_args(argc, argv))
		return (0);
	table = init_table(argc, argv);
	table.children = malloc(sizeof(pid_t) * table.size);
	if (!table.children)
		return (0);
	pthread_create(&die_mntr, NULL, monitor_die, &table);
	pthread_create(&eat_mntr, NULL, monitor_eat, &table);
	pthread_create(&order_mntr, NULL, monitor_order, &table);
	create_processes(&table);
	pthread_join(die_mntr, NULL);
	pthread_join(eat_mntr, NULL);
	killall(table.size, table.children);
	return (0);
}
