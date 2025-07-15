/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:26:43 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/15 19:32:04 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	printter(t_philo *philo, enum e_philo_state action)
{
	static char	*msgs[6] = {
		"is thinking",
		"has taken a fork",
		"has taken a fork",
		"is eating",
		"is sleeping",
		"died"
	};
	t_ms		ms;
	int			is_die;

	pthread_mutex_lock(&philo->program_data->printter_mutex);
	if (action == STATE_DIE)
		is_die = 1;
	else
		is_die = get_die_flag(philo->program_data);
	if (action == STATE_DIE || is_die == 0)
	{
		ms = get_time_ms() - philo->program_data->start_time;
		printf("%ld %d %s\n", ms, philo->id, msgs[action]);
	}
	pthread_mutex_unlock(&philo->program_data->printter_mutex);
	return (is_die);
}
