/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 13:59:39 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/13 15:49:30 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_philo
{
	int				index;
	long			meal_count;
	long			time_last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*meal_lock;
	struct s_sim	*sim;
}	t_philo;

typedef struct s_sim
{
	int				number_philos;
	long			time_to_die;
	long			time_to_sleep;
	long			time_to_eat;
	long			start_time;
	int				must_eat; // -1 se não especificado
	int				stop_sim; // flag de parada (0 = rodando, 1 = parar)
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*stop_lock;
	t_philo			*philos;
}	t_sim;

#endif