/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:38:38 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/10 15:37:40 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philos[i].program_data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[i + 1 % data->n_philo];
		data->philos[i].last_timestamp = 0; // !
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		i++;
	}
}

void	free_forks(t_fork *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
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
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (free_forks(data->forks, i), free(data->philos), 1);
		i++;
	}
	init_philos(data);
	return (0);
}
