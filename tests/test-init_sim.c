// tests/test-init_sim.c
#include "tests.h"
#include "../philosophers.h"

int test_init_sim_basic(void)
{
	t_sim sim;
	memset(&sim, 0, sizeof(t_sim));
	sim.number_philos = 4;
	sim.time_to_die = 800;
	int ret = init_sim(&sim, 0);
	if (ret != 0)
		return (EXIT_FAILURE);
	// Verifica se os arrays foram alocados e mutexes inicializados
	if (sim.forks == NULL || sim.philos == NULL
		|| sim.print_lock == NULL || sim.stop_lock == NULL)
		return (EXIT_FAILURE);
	// Tenta dar lock em um garfo
	if (pthread_mutex_lock(&sim.forks[0]) != 0)
		return (EXIT_FAILURE);
	pthread_mutex_unlock(&sim.forks[0]);
	cleanup_sim(&sim, sim.number_philos);
	return (EXIT_SUCCESS);
}

int main(void)
{
	RUN_TEST(test_init_sim_basic);
	return (0);
}
