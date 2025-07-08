/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:44:48 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/08 16:02:56 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	long long	initial_time;

	if (argc < 5 || argc > 6)
		return (1);
	(void)argv;
	initial_time = get_time_in_ms();
	print_action(initial_time, 1, STATE_TAKE_FORK);
	usleep(500000);
	print_action(initial_time, 2, STATE_EAT);
	usleep(500000);
	print_action(initial_time, 3, STATE_SLEEP);
	usleep(500000);
	print_action(initial_time, 4, STATE_THINK);
	usleep(500000);
	print_action(initial_time, 4, STATE_DIE);
	return (0);
}
