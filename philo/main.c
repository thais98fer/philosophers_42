/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:54:56 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/16 15:21:49 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	memset(&sim, 0, sizeof(t_sim));
	if (parse_args(argc, argv, &sim))
		return (1);
	if (init_sim(&sim, 0))
	{
		printf("Error: initialization failed\n");
		return (1);
	}
	// threads
	cleanup_sim(&sim, sim.number_philos);
	return (0);
}
