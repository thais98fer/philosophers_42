/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:24:02 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/16 18:43:00 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_death(t_sim *sim, int i)
{
	unsigned long	now;

	pthread_mutex_lock(sim->philos[i].meal_lock);
	now = get_time_ms();
	if (now - sim->philos[i].time_last_meal > sim->time_to_die)
	{
		print_status(sim, sim->philos[i].index, "died");
		pthread_mutex_lock(sim->stop_lock);
		sim->stop_sim = 1;
		pthread_mutex_unlock(sim->stop_lock);
		pthread_mutex_unlock(sim->philos[i].meal_lock);
		return (1);
	}
	pthread_mutex_unlock(sim->philos[i].meal_lock);
	return (0);
}

static int	all_ate(t_sim *sim)
{
	int	i;
	int	count;

	if (sim->must_eat == -1)
		return (0);
	i = 0;
	count = 0;
	while (i < sim->number_philos)
	{
		pthread_mutex_lock(sim->philos[i].meal_lock);
		if (sim->philos[i].meal_count >= (unsigned long)sim->must_eat)
			count++;
		pthread_mutex_unlock(sim->philos[i].meal_lock);
		i++;
	}
	if (count == sim->number_philos)
	{
		pthread_mutex_lock(sim->stop_lock);
		sim->stop_sim = 1;
		pthread_mutex_unlock(sim->stop_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_sim	*sim;
	int		i;

	sim = (t_sim *)arg;
	while (1)
	{
		i = 0;
		while (i < sim->number_philos)
		{
			if (check_death(sim, i))
				return (NULL);
			i++;
		}
		if (all_ate(sim))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
