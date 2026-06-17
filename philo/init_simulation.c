/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:06:03 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/17 17:07:11 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_forks(t_sim *sim)
{
	int	i;

	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->number_philos);
	if (!sim->forks)
		return (1);
	i = 0;
	while (i < sim->number_philos)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	return (0);
}

static int	init_philos_array(t_sim *sim)
{
	sim->philos = malloc(sizeof(t_philo) * sim->number_philos);
	if (!sim->philos)
		return (1);
	return (0);
}

static int	init_global_locks(t_sim *sim)
{
	sim->print_lock = malloc(sizeof(pthread_mutex_t));
	sim->stop_lock = malloc(sizeof(pthread_mutex_t));
	if (!sim->print_lock || !sim->stop_lock)
	{
		if (sim->print_lock)
			free(sim->print_lock);
		if (sim->stop_lock)
			free(sim->stop_lock);
		return (1);
	}
	pthread_mutex_init(sim->print_lock, NULL);
	pthread_mutex_init(sim->stop_lock, NULL);
	return (0);
}

static int	init_philosopher(t_philo *philo, int i, t_sim *sim)
{
	philo->index = i + 1;
	philo->meal_count = 0;
	philo->time_last_meal = 0;
	philo->left_fork = &sim->forks[i];
	philo->right_fork = &sim->forks[(i + 1) % sim->number_philos];
	philo->meal_lock = malloc(sizeof(pthread_mutex_t));
	if (!philo->meal_lock)
		return (1);
	pthread_mutex_init(philo->meal_lock, NULL);
	philo->sim = sim;
	return (0);
}

int	init_sim(t_sim *sim, int i)
{
	sim->stop_sim = 0;
	if (init_forks(sim))
		return (1);
	if (init_philos_array(sim))
	{
		destroy_forks(sim);
		return (1);
	}
	if (init_global_locks(sim))
	{
		clear_philos_and_forks(sim);
		return (1);
	}
	while (i < sim->number_philos)
	{
		if (init_philosopher(&sim->philos[i], i, sim))
		{
			cleanup_sim(sim, i);
			return (1);
		}
		i++;
	}
	return (0);
}
