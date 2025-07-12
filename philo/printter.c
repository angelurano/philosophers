/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:26:43 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/12 11:46:12 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printter(t_philo *philo, enum e_philo_state action)
{
	static char	*msgs[6] = {
		"thinking",
		"has taken a fork",
		"has taken a fork",
		"is eating",
		"is sleeping",
		"died"
	};
	t_ms		ms;

	pthread_mutex_lock(&philo->program_data->printter_mutex);
	if (action == STATE_DIE || get_die_flag(philo->program_data) == 0)
	{
		ms = get_time_ms() - philo->program_data->start_time;
		printf("%lld %d %s\n", ms, philo->id, msgs[action]);
	}
	pthread_mutex_unlock(&philo->program_data->printter_mutex);
}
