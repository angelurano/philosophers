/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:25:31 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/15 19:43:41 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

t_ms	min_ms(t_ms first, t_ms second)
{
	if (first < second)
		return (first);
	return (second);
}

t_ms	abs_ms(t_ms value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	ft_usleep(useconds_t usec)
{
	if (usec <= 0)
		return (0);
	return (usleep(usec));
}
