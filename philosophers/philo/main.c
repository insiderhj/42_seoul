/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:45:20 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/05 12:40:39 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"


int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6 || ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0
		|| (argc == 6 && ft_atoi(argv[5]) <= 0))
		return (0);
	table = create_table();
	if (!table)
		return (0);
	pthread_mutex_lock(&table->global_mutex);
	if (!init_table(table, argc, argv))
		return (free_table(table));
	create_threads(table);
	gettimeofday(&table->start_time, NULL);
	pthread_mutex_unlock(&table->global_mutex);
	while (check_table(table))
		usleep(100);
	return (free_table(table));
}
