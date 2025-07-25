/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:23:46 by migugar2          #+#    #+#             */
/*   Updated: 2025/07/15 19:32:36 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_positive_int(char *arg, int *out)
{
	int	res;
	int	digit;
	int	i;

	i = 0;
	while (arg[i] && ft_isspace(arg[i]))
		i++;
	if (arg[i] == '+')
		i++;
	res = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		digit = arg[i] - '0';
		if (res > (INT_MAX - digit) / 10)
			return (1);
		res = res * 10 + digit;
		i++;
	}
	*out = res;
	return (0);
}

static int	parse_ms(char *arg, t_ms *out)
{
	t_ms	res;
	int		digit;
	int		i;

	i = 0;
	while (arg[i] && ft_isspace(arg[i]))
		i++;
	if (arg[i] == '+')
		i++;
	res = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		digit = arg[i] - '0';
		if (res > (LONG_MAX - digit) / 10)
			return (1);
		res = res * 10 + digit;
		i++;
	}
	if (res <= 0)
		return (1);
	*out = res;
	return (0);
}

int	parse_input(int argc, char *argv[], t_data *data)
{
	if (parse_positive_int(argv[1], &data->n_philo) == 1
		|| data->n_philo <= 0)
		return (1);
	if (parse_ms(argv[2], &data->die_time) == 1)
		return (1);
	if (parse_ms(argv[3], &data->eat_time) == 1)
		return (1);
	if (parse_ms(argv[4], &data->sleep_time) == 1)
		return (1);
	data->n_philo_must_eat = -1;
	if (argc == 6)
	{
		if (parse_positive_int(argv[5], &data->n_philo_must_eat) == 1)
			return (1);
	}
	return (0);
}
