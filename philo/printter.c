/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:26:43 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/11 15:19:56 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	printter(t_ms start, int p_id, enum e_philo_state action)
{
	static char	*msgs[6] = {
		"thinking",
		"has taken a fork",
		"has taken a fork",
		"is eating",
		"is sleeping",
		"died"
	};
	t_ms		ms;

	ms = get_time_ms() - start;
	printf("%lld %d %s\n", ms, p_id, msgs[action]);
}
