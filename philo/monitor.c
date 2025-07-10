/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:34:43 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/10 18:38:48 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_philo_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->philos[i].eat_count < data->n_philo_must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor(t_data	*data)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < data->n_philo)
		{
			if (data->philos[i].last_meal != 0 && get_time_in_ms() - data->philos[i].last_meal > data->die_time)
			{
				data->die_flag = 1;
				print_action(data->start_time, data->philos[i].id, STATE_DIE);
				return (NULL);
			}
			i++;
		}
		if (data->n_philo_must_eat != -1 && all_philo_eat(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philosopher_thread, &data->philos[i]) != 0)
		{
			data->die_flag = 1;
			return (1);
		}
		i++;
	}
	monitor(data);
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
