/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:50:46 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/11 16:05:43 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_thread(void *arg)
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
	return (NULL);
}
