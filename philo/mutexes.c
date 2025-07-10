/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:46:52 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/10 20:47:29 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_die_flag(t_data *data)
{
	int	flag;

	pthread_mutex_lock(&data->die_flag_mutex);
	flag = data->die_flag;
	pthread_mutex_unlock(&data->die_flag_mutex);
	return (flag);
}
