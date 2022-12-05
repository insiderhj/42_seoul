/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:51:27 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/05 11:46:02 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <sys/time.h>

typedef enum e_stat {
	AVAILABLE,
	USING
}	t_stat;

typedef struct s_philo {
	struct s_table	*table;
	pthread_t		thread;
	int				last_eat;
	int				idx;
	int				eaten;
}	t_philo;

typedef struct s_table {
	int				size;
	int				ttd;
	int				tte;
	int				tts;
	int				must_eat;
	int				done;
	t_philo			*philo;
	t_stat			*forks;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	global_mutex;
	struct timeval	start_time;
}	t_table;

// philo_utils.c
int		ft_atoi(const char *s);
int		get_ms(struct timeval start_time);
int		print_state(t_table *table, int idx, char *str, int done);

// table.c
t_table	*create_table(void);
int		init_table(t_table *table, int argc, char **argv);
int		check_table(t_table *table);
int		free_table(t_table *table);

// threads.c
void	create_threads(t_table *table);
void	join_all(t_table *table);

// philo.c
void	*create_philo(void *arg);
int		is_turn(t_table *table, t_philo *philo);
void	take_fork(t_philo *philo);
void	pick_fork(t_table *table, int idx);
void	put_fork(t_table *table, t_philo *philo);

#endif
