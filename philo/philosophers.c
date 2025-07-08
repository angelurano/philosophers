/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:44:48 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/08 17:59:01 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		return (1);
	philo.start_time = get_time_in_ms();
	if (parse_input(argc, argv, &philo) == 1)
		return (1);
	printf("number_of_philosophers: %d,\n", philo.n_philo);
	printf("time_to_die: %lld,\n", philo.die_time);
	printf("time_to_eat: %lld,\n", philo.eat_time);
	printf("time_to_sleep: %lld,\n", philo.sleep_time);
	printf("number_of_times_each_philosopher_must_eat: %d,\n", philo.n_philo_must_eat);
	printf("Start Time in ms: %lld\n", philo.start_time);
	return (0);
}
