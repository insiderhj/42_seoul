/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:51:27 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/08 03:39:40 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo {
	int				idx;
	int				last_eat;
	int				eaten;
	pthread_mutex_t	eat_mutex;
}	t_philo;

typedef struct s_table {
	int				valid;
	int				size;
	int				ttd;
	int				tte;
	int				tts;
	int				must_eat;
	pid_t			*children;
	struct timeval	start_time;
	sem_t			*odd_sem;
	sem_t			*even_sem;
	sem_t			*last_sem;
	sem_t			*turn_sem;
	sem_t			*global_sem;
	sem_t			*forks;
	sem_t			*die_monitor;
	sem_t			*eat_monitor;
}	t_table;

typedef struct s_info {
	t_table	table;
	t_philo	*philo;
}	t_info;

// philo_utils_bonus.c
int		ft_atoi(const char *s);
int		get_ms(struct timeval start_time);
int		print_state(t_table table, t_philo *philo, char *str, int die);
sem_t	*init_sem(char *name, int value);

// philo_bonus.c
void	create_processes(t_table *table);
void	create_philo(t_table table, t_philo philo);
void	philo_loop(t_table table, t_philo *philo);

// monitor_bonus.c
void	*monitor_die(void *param);
void	*monitor_eat(void *param);
void	*monitor_order(void *param);
void	*monitor_philo(void *param);

#endif
