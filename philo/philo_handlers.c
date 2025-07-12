/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:15:37 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/12 12:24:57 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_philo_state	think_handler(t_philo *philo)
{
	printter(philo, STATE_THINK);
	return (STATE_1_FORK);
}

// TODO: Check if need to change the behavior of taking forks for deadlock prevention
enum e_philo_state	take1_handler(t_philo *philo)
{
	if (philo->program_data->n_philo % 2 == 0 && philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	/*
	if (philo->program_data->n_philo % 2 == 0 && philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	*/
	if (get_die_flag(philo->program_data) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (STATE_DIE);
	}
	printter(philo, STATE_1_FORK);
	if (philo->program_data->n_philo == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (STATE_DIE);
	}
	return (STATE_2_FORK);
}

enum e_philo_state	take2_handler(t_philo *philo)
{
	if (philo->program_data->n_philo % 2 == 0 && philo->id % 2 == 0)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	if (get_die_flag(philo->program_data) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (STATE_DIE);
	}
	printter(philo, STATE_2_FORK);
	return (STATE_EAT);
}

enum e_philo_state	eat_handler(t_philo *philo)
{
	printter(philo, STATE_EAT);
	set_eat_info(philo);
	usleep(philo->program_data->eat_time * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (STATE_SLEEP);
}

enum e_philo_state	sleep_handler(t_philo *philo)
{
	printter(philo, STATE_SLEEP);
	usleep(philo->program_data->sleep_time * 1000);
	return (STATE_THINK);
}
