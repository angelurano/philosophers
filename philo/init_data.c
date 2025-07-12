/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:38:38 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/12 11:29:37 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_data_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philos[i].program_data = data;
		data->philos[i].left_fork = &data->forks[i];
		if (data->n_philo == 1)
			data->philos[i].right_fork = NULL;
		else
			data->philos[i].right_fork = &data->forks[(i + 1) % data->n_philo];
		data->philos[i].last_meal = 0;
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		i++;
	}
}

int	init_data(t_data *data)
{
	int	i;

	data->philos = malloc(data->n_philo * sizeof(t_philo));
	if (data->philos == NULL)
		return (1);
	data->forks = malloc(data->n_philo * sizeof(t_fork));
	if (data->forks == NULL)
		return (free(data->philos), 1);
	if (pthread_mutex_init(&data->die_flag_mutex, NULL) != 0)
		return (free_forks(data->forks, data->n_philo), free(data->philos), 1);
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (free_forks(data->forks, i), free(data->philos),
				pthread_mutex_destroy(&data->die_flag_mutex), 1);
		i++;
	}
	init_data_philos(data);
	data->die_flag = 0;
	return (0);
}
