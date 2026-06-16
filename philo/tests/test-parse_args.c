#include "tests.h"
#include "../philosophers.h"

int test_parse_args_correct(void)
{
	t_sim sim;
	memset(&sim, 0, sizeof(t_sim));
	char *argv[] = {"./philo", "5", "800", "200", "200", NULL};
	if (parse_args(5, argv, &sim) != 0)
		return (EXIT_FAILURE);
	if (sim.number_philos != 5 || sim.time_to_die != 800
		|| sim.time_to_eat != 200 || sim.time_to_sleep != 200
		|| sim.must_eat != -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int test_parse_args_must_eat(void)
{
	t_sim sim;
	memset(&sim, 0, sizeof(t_sim));
	char *argv[] = {"./philo", "5", "800", "200", "200", "7", NULL};
	if (parse_args(6, argv, &sim) != 0)
		return (EXIT_FAILURE);
	if (sim.must_eat != 7)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int test_parse_args_invalid_count(void)
{
	int saved = start_capture();
	t_sim sim;
	char *argv[] = {"./philo", "5", NULL};
	int ret = parse_args(2, argv, &sim);
	char *output = end_capture(saved);
	if (ret != 1 || !strstr(output, "wrong number of arguments"))
	{
		free(output);
		return (EXIT_FAILURE);
	}
	free(output);
	return (EXIT_SUCCESS);
}

int test_parse_args_negative_number(void)
{
	int	saved = start_capture();
	t_sim sim;
	char *argv[] = {"./philo", "-5", "800", "200", "200", NULL};
	int ret = parse_args(5, argv, &sim);
	char *output = end_capture(saved);
	if (ret != 1 || !strstr(output, "must be only numbers"))
	{
		free(output);
		return (EXIT_FAILURE);
	}
	free(output);
	return (EXIT_SUCCESS);
}

int main(void)
{
	RUN_TEST(test_parse_args_correct);
	RUN_TEST(test_parse_args_must_eat);
	RUN_TEST(test_parse_args_invalid_count);
	RUN_TEST(test_parse_args_negative_number);
	return (0);
}
