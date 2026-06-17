/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 13:59:20 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/17 20:11:19 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_valid_number(const char *str)
{
	if (*str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static int	validate_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			printf("Error: invalid type of argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	validate_values(t_sim *sim, int argc)
{
	if (sim->number_philos <= 0 || sim->time_to_die <= 0
		|| sim->time_to_eat <= 0 || sim->time_to_sleep <= 0)
	{
		printf("Error: arguments must be above zero and < INT_MAX\n");
		return (1);
	}
	if (argc == 6 && sim->must_eat <= 0)
	{
		printf("Error: [number_of_times_each_must_eat] must be positive\n");
		return (1);
	}
	if (sim->number_philos > 200)
	{
		printf("Error: too many philosophers\n");
		return (1);
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_sim *sim)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		printf("[Number_of_philosophers] [time_to_die] [time_to_eat] \
[time_to_sleep] [number_of_times_each_philo_must_eat]");
		return (1);
	}
	if (validate_numbers(argc, argv))
		return (1);
	sim->number_philos = (int)ft_atol(argv[1]);
	sim->time_to_die = (unsigned long)ft_atol(argv[2]);
	sim->time_to_eat = (unsigned long)ft_atol(argv[3]);
	sim->time_to_sleep = (unsigned long)ft_atol(argv[4]);
	if (argc == 6)
		sim->must_eat = (int)ft_atol(argv[5]);
	else
		sim->must_eat = -1;
	if (validate_values(sim, argc))
		return (1);
	return (0);
}
