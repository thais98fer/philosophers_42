/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:54:56 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/17 15:59:04 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_sim *sim, int id, char *message)
{
	pthread_mutex_lock(sim->stop_lock);
	if (!sim->stop_sim)
	{
		pthread_mutex_lock(sim->print_lock);
		printf("%lu %d %s\n", get_time_ms() - sim->start_time, id, message);
		pthread_mutex_unlock(sim->print_lock);
	}
	pthread_mutex_unlock(sim->stop_lock);
}

void	create_threads(t_sim *sim, pthread_t *monitor)
{
	int	i;

	pthread_create(monitor, NULL, monitor_routine, sim);
	i = 0;
	while (i < sim->number_philos)
	{
		pthread_create(&sim->philos[i].thread_id, NULL,
			philo_routine, &sim->philos[i]);
		i++;
	}
}

void	join_threads(t_sim *sim, pthread_t monitor)
{
	int	i;

	pthread_join(monitor, NULL);
	i = 0;
	while (i < sim->number_philos)
	{
		pthread_join(sim->philos[i].thread_id, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_sim		sim;
	int			i;
	pthread_t	monitor_thread;

	memset(&sim, 0, sizeof(t_sim));
	if (parse_args(argc, argv, &sim))
		return (1);
	if (init_sim(&sim, 0))
	{
		printf("Error: initialization failed\n");
		return (1);
	}
	sim.start_time = get_time_ms();
	i = 0;
	while (i < sim.number_philos)
	{
		sim.philos[i].time_last_meal = sim.start_time;
		i++;
	}
	create_threads(&sim, &monitor_thread);
	join_threads(&sim, monitor_thread);
	cleanup_sim(&sim, sim.number_philos);
	return (0);
}
