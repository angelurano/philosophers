/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:46:52 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/12 12:22:03 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_die_flag(t_data *data)
{
	int	flag;

	pthread_mutex_lock(&data->die_flag_mutex);
	flag = data->die_flag;
	pthread_mutex_unlock(&data->die_flag_mutex);
	return (flag);
}

void	set_eat_info(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_info_mutex);
	philo->last_eat_time = get_time_ms();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_info_mutex);
}

t_ms	get_eat_time(t_philo *philo)
{
	t_ms	last_eat_time;

	pthread_mutex_lock(&philo->eat_info_mutex);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->eat_info_mutex);
	return (last_eat_time);
}

int	get_eat_count(t_philo *philo)
{
	int	eat_count;

	pthread_mutex_lock(&philo->eat_info_mutex);
	eat_count = philo->eat_count;
	pthread_mutex_unlock(&philo->eat_info_mutex);
	return (eat_count);
}
