/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:50:46 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/12 12:58:10 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_first_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	philo->first_taken = 1;
}

void	take_second_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->second_fork);
	philo->second_taken = 1;
}

void	release_first_fork(t_philo *philo)
{
	if (philo->first_taken)
	{
		pthread_mutex_unlock(philo->first_fork);
		philo->first_taken = 0;
	}
}

void	release_second_fork(t_philo *philo)
{
	if (philo->second_taken)
	{
		pthread_mutex_unlock(philo->second_fork);
		philo->second_taken = 0;
	}
}

void	*philosopher_routine(void *arg)
{
	static enum e_philo_state	(*handlers[5])(t_philo *) = {
		think_handler,
		take1_handler,
		take2_handler,
		eat_handler,
		sleep_handler
	};
	enum e_philo_state			state;
	t_philo						*philo;

	philo = (t_philo *)arg;
	state = STATE_THINK;
	while (state != STATE_DIE
		&& get_die_flag(philo->program_data) == 0
		&& (philo->program_data->n_philo_must_eat == -1
			|| philo->eat_count < philo->program_data->n_philo_must_eat))
		state = handlers[state](philo);
	if (philo->first_taken)
		release_first_fork(philo);
	if (philo->second_taken)
		release_second_fork(philo);
	return (NULL);
}
