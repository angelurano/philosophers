/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:22 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/12 12:11:48 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
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

void	free_eat_mutexes(t_philo *philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&philos[i].eat_info_mutex);
		i++;
	}
}

void	free_all(t_data *data, int count, int is_init)
{
	if (!is_init)
		free_eat_mutexes(data->philos, count);
	pthread_mutex_destroy(&data->die_flag_mutex);
	pthread_mutex_destroy(&data->printter_mutex),
	free_forks(data->forks, count);
	free(data->philos);
}
