/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:44:38 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/10 17:11:03 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> // memset
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h>
// pthread_create, pthread_detach, pthread_join
// pthread_mutex_init, pthread_mutex_destroy
// pthread_mutex_lock, pthread_mutex_unlock
// pthread_mutex_t

# include <sys/types.h> // usecondst_t
# include <limits.h>

enum e_philo_state
{
	STATE_THINK,
	STATE_1_FORK,
	STATE_2_FORK,
	STATE_EAT,
	STATE_SLEEP,
	STATE_DIE
};

typedef pthread_mutex_t	t_fork;

typedef long long		t_ms;

typedef struct s_philo
{
	struct s_data	*program_data;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread; // 8 bytes
	t_ms			last_meal;
	int				id;
	int				eat_count;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	die_flag_mutex;
	t_fork			*forks;
	t_philo			*philos;
	t_ms			start_time;
	t_ms			die_time;
	t_ms			eat_time;
	t_ms			sleep_time;
	int				n_philo;
	int				n_philo_must_eat;
	int				die_flag;
}	t_data;

enum e_philo_state	think_handler(t_philo *philo);
enum e_philo_state	take1_handler(t_philo *philo);
enum e_philo_state	take2_handler(t_philo *philo);
enum e_philo_state	eat_handler(t_philo *philo);
enum e_philo_state	sleep_handler(t_philo *philo);

int					parse_input(int argc, char *argv[], t_data *data);

int					init_data(t_data *data);
void				free_forks(t_fork *forks, int count);

int					get_die_flag(t_data *data);

void				*philosopher_thread(void *arg);

void				*monitor(t_data	*data);
int					init_threads(t_data *data);
void				join_threads(t_data *data);

t_ms				get_time_ms(void);
void				printter(t_ms start, int p_id, enum e_philo_state action);

#endif
