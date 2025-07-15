/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:34:43 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/15 19:06:29 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_philo_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (get_eat_count(&data->philos[i]) < data->n_philo_must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	monitor_routine(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_lock(&data->die_flag_mutex);
			if (get_time_ms() - get_eat_time(&data->philos[i])
				>= data->die_time)
			{
				data->die_flag = 1;
				pthread_mutex_unlock(&data->die_flag_mutex);
				printter(&data->philos[i], STATE_DIE);
				return ;
			}
			pthread_mutex_unlock(&data->die_flag_mutex);
			i++;
		}
		if (data->n_philo_must_eat != -1 && all_philo_eat(data))
			return ;
		usleep(1000);
	}
}

int	init_routines(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time_ms();
	while (i < data->n_philo)
	{
		data->philos[i].last_eat_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL,
				philosopher_routine, &data->philos[i]) != 0)
		{
			pthread_mutex_lock(&data->die_flag_mutex);
			data->die_flag = 1;
			pthread_mutex_unlock(&data->die_flag_mutex);
			return (1);
		}
		i++;
	}
	monitor_routine(data);
	return (0);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}
