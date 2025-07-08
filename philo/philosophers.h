/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:44:38 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/08 15:57:27 by migugar2         ###   ########.fr       */
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

# define STATE_TAKE_FORK 0
# define STATE_EAT 1
# define STATE_SLEEP 2
# define STATE_THINK 3
# define STATE_DIE 4

typedef pthread_mutex_t	t_fork;

long long	get_time_in_ms(void);
void		print_action(long long start, int philosopher, int action);

#endif
