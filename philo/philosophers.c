/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:44:48 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/10 15:39:49 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (1);
	if (parse_input(argc, argv, &data) == 1)
		return (1);
	if (init_data(&data) == 1)
		return (1);
	// TODO

	free_forks(data.forks, data.n_philo);
	free(data.philos);
	return (0);
}
