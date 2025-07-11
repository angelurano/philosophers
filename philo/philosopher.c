/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:15:37 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/10 21:59:00 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_take(t_philo *philo, enum e_philo_state state)
{
	// TODO: Control 1 philosopher (1 fork)
	if (state == STATE_1_FORK)
	{
		pthread_mutex_lock(philo->left_fork);
		/*
		if (philo->id == 1)
			pthread_mutex_lock(philo->right_fork);
		else
			pthread_mutex_lock(philo->left_fork);
		*/
	}
	else if (state == STATE_2_FORK)
	{
		pthread_mutex_lock(philo->right_fork);
		/*
		if (philo->id == 1)
			pthread_mutex_lock(philo->left_fork);
		else
			pthread_mutex_lock(philo->right_fork);
		*/
	}
	if (get_die_flag(philo->program_data) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	print_action(philo->program_data->start_time, philo->id, state);
}

void	philosopher_eat(t_philo *philo)
{
	print_action(philo->program_data->start_time, philo->id, STATE_EAT);
	philo->last_meal = get_time_ms();
	philo->eat_count++;
	usleep(philo->program_data->eat_time * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philosopher_sleep(t_philo *philo)
{
	print_action(philo->program_data->start_time, philo->id, STATE_SLEEP);
	usleep(philo->program_data->sleep_time * 1000);
}

void	do_next_action(t_philo *philo, enum e_philo_state *state)
{
	if (*state == STATE_THINK)
	{
		print_action(philo->program_data->start_time, philo->id, STATE_THINK);
		*state = STATE_1_FORK;
	}
	else if (*state == STATE_1_FORK)
	{
		philosopher_take(philo, *state);
		*state = STATE_2_FORK;
	}
	else if (*state == STATE_2_FORK)
	{
		philosopher_take(philo, *state);
		*state = STATE_EAT;
	}
	else if (*state == STATE_EAT)
	{
		philosopher_eat(philo);
		*state = STATE_SLEEP;
	}
	else if (*state == STATE_SLEEP)
	{
		philosopher_sleep(philo);
		*state = STATE_THINK;
	}
}

void	*philosopher_thread(void *arg)
{
	enum e_philo_state	state;
	t_philo				*philo;

	philo = (t_philo *)arg;
	state = STATE_THINK;
	while (get_die_flag(philo->program_data) == 0
		&& (philo->program_data->n_philo_must_eat == -1
			|| philo->eat_count < philo->program_data->n_philo_must_eat))
	{
		do_next_action(philo, &state);
	}
	return (NULL);
}
