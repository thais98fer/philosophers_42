/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:20:10 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/16 15:21:38 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_meal_locks(t_sim *sim, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		pthread_mutex_destroy(sim->philos[j].meal_lock);
		free(sim->philos[j].meal_lock);
		j++;
	}
}

void	destroy_forks(t_sim *sim)
{
	int	j;

	j = 0;
	while (j < sim->number_philos)
	{
		pthread_mutex_destroy(&sim->forks[j]);
		j++;
	}
	free(sim->forks);
}

void	cleanup_sim(t_sim *sim, int philos_initialized)
{
	destroy_meal_locks(sim, philos_initialized);
	if (sim->print_lock)
	{
		pthread_mutex_destroy(sim->print_lock);
		free(sim->print_lock);
	}
	if (sim->stop_lock)
	{
		pthread_mutex_destroy(sim->stop_lock);
		free(sim->stop_lock);
	}
	if (sim->philos)
		free(sim->philos);
	if (sim->forks)
		destroy_forks(sim);
}

int	clear_philos_and_forks(t_sim *sim)
{
	destroy_forks(sim);
	free(sim->philos);
	return (1);
}
