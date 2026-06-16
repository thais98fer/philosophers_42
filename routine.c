/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:37:44 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/16 18:06:18 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->time_last_meal = get_time_ms();
	philo->meal_count++;
	pthread_mutex_unlock(philo->meal_lock);
	print_status(philo->sim, philo->index, "is eating");
	ft_usleep(philo->sim->time_to_eat);
}

static void	*handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo->sim, philo->index, "has taken a fork");
	ft_usleep(philo->sim->time_to_die);
	print_status(philo->sim, philo->index, "died");
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

// take forks (lowest address first)
static void	take_forks(t_philo *philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo->sim, philo->index, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo->sim, philo->index, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo->sim, philo->index, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo->sim, philo->index, "has taken a fork");
	}
}

static int	should_stop(t_sim *sim)
{
	int	stop;

	pthread_mutex_lock(sim->stop_lock);
	stop = sim->stop_sim;
	pthread_mutex_unlock(sim->stop_lock);
	return (stop);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->sim->number_philos == 1)
		return (handle_single_philo(philo));
	if (philo->index % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (should_stop(philo->sim))
			break ;
		print_status(philo->sim, philo->index, "is thinking");
		take_forks(philo);
		philo_eat(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (should_stop(philo->sim))
			break ;
		print_status(philo->sim, philo->index, "is sleeping");
		ft_usleep(philo->sim->time_to_sleep);
	}
	return (NULL);
}
