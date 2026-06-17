/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:17:08 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/17 16:31:20 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	get_time_ms(void)
{
	struct timeval	timeval;
	unsigned long	milliseconds;

	gettimeofday(&timeval, NULL);
	milliseconds = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	return (milliseconds);
}

void	ft_usleep(unsigned long milliseconds)
{
	unsigned long	start;

	start = get_time_ms();
	while (get_time_ms() - start < milliseconds)
		usleep(500);
}
