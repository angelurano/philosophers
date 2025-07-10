/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:26:43 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/10 19:58:14 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	print_action(t_ms start, int philosopher, enum e_philo_state action)
{
	t_ms	ms;

	ms = get_time_ms() - start;
	if (action == STATE_1_FORK || action == STATE_2_FORK)
		printf("%lld %d has taken a fork\n", ms, philosopher);
	else if (action == STATE_EAT)
		printf("%lld %d is eating\n", ms, philosopher);
	else if (action == STATE_SLEEP)
		printf("%lld %d is sleeping\n", ms, philosopher);
	else if (action == STATE_THINK)
		printf("%lld %d is thinking\n", ms, philosopher);
	else if (action == STATE_DIE)
		printf("%lld %d died\n", ms, philosopher);
}
