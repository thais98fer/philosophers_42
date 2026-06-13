#include "tests.h"
#include "../philosophers.h"

int	sample_success(void)
{
	if (sample() == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(sample_success);
}