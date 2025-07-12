/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:38:38 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/12 12:40:29 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo)
{
	t_fork	*left_fork;
	t_fork	*right_fork;
	int		index;

	left_fork = &philo->program_data->forks[philo->id - 1];
	if (philo->program_data->n_philo > 1)
	{
		index = philo->id % philo->program_data->n_philo;
		right_fork = &philo->program_data->forks[index];
	}
	else
		right_fork = NULL;
	if (philo->id % 2 != 0)
	{
		philo->first_fork = left_fork;
		philo->second_fork = right_fork;
	}
	else
	{
		philo->first_fork = right_fork;
		philo->second_fork = left_fork;
	}
}

static int	init_data_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->philos[i].eat_info_mutex, NULL) != 0)
			return (free_eat_mutexes(data->philos, i), 1);
		data->philos[i].id = i + 1;
		data->philos[i].program_data = data;
		data->philos[i].first_taken = 0;
		data->philos[i].second_taken = 0;
		data->philos[i].eat_count = 0;
		assign_forks(&data->philos[i]);
		i++;
	}
	return (0);
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
	if (pthread_mutex_init(&data->printter_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&data->die_flag_mutex),
			free_forks(data->forks, data->n_philo), free(data->philos), 1);
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (free_all(data, i, 1), 1);
		i++;
	}
	if (init_data_philos(data) == 1)
		return (free_all(data, data->n_philo, 1), 1);
	data->die_flag = 0;
	return (0);
}
