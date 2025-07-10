/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:44:38 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/10 15:37:57 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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

# define STATE_TAKE_FORK 0
# define STATE_EAT 1
# define STATE_SLEEP 2
# define STATE_THINK 3
# define STATE_DIE 4

typedef pthread_mutex_t	t_fork;

typedef long long		t_ms;

typedef struct s_philo
{
	struct s_data	*program_data;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_ms			last_timestamp;
	int				id;
	int				eat_count;
}	t_philo;

typedef struct s_data
{
	t_philo	*philos;
	t_fork	*forks;
	t_ms	start_time;
	t_ms	die_time;
	t_ms	eat_time;
	t_ms	sleep_time;
	int		n_philo;
	int		n_philo_must_eat;
}	t_data;

int		parse_input(int argc, char *argv[], t_data *data);

int		init_data(t_data *data);
void	free_forks(t_fork *forks, int count);

t_ms	get_time_in_ms(void);
void	print_action(t_ms start, int philosopher, int action);

#endif
