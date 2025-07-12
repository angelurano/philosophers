/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:15:37 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/12 13:03:48 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_philo_state	think_handler(t_philo *philo)
{
	if (printter(philo, STATE_THINK) == 1)
		return (STATE_DIE);
	return (STATE_1_FORK);
}

enum e_philo_state	take1_handler(t_philo *philo)
{
	take_first_fork(philo);
	if (printter(philo, STATE_1_FORK) == 1 || philo->program_data->n_philo == 1)
	{
		release_first_fork(philo);
		return (STATE_DIE);
	}
	return (STATE_2_FORK);
}

enum e_philo_state	take2_handler(t_philo *philo)
{
	take_second_fork(philo);
	if (printter(philo, STATE_2_FORK) == 1)
	{
		release_first_fork(philo);
		release_second_fork(philo);
		return (STATE_DIE);
	}
	return (STATE_EAT);
}

enum e_philo_state	eat_handler(t_philo *philo)
{
	int	is_die;

	is_die = printter(philo, STATE_EAT);
	if (is_die == 0)
	{
		set_eat_info(philo);
		usleep(philo->program_data->eat_time * 1000);
	}
	release_first_fork(philo);
	release_second_fork(philo);
	if (is_die == 1)
		return (STATE_DIE);
	return (STATE_SLEEP);
}

enum e_philo_state	sleep_handler(t_philo *philo)
{
	if (printter(philo, STATE_SLEEP) == 1)
		return (STATE_DIE);
	usleep(philo->program_data->sleep_time * 1000);
	return (STATE_THINK);
}
