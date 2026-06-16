#include "tests.h"
#include "../philosophers.h"

int test_ft_atol_positive(void)
{
	if (ft_atol("42") != 42)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int test_ft_atol_negative(void)
{
	if (ft_atol("-42") != -42)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int test_ft_atol_overflow(void)
{
	if (ft_atol("2147483648") != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int test_ft_atol_invalid(void)
{
	if (ft_atol("12a34") != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int main(void)
{
	RUN_TEST(test_ft_atol_positive);
	RUN_TEST(test_ft_atol_negative);
	RUN_TEST(test_ft_atol_overflow);
	RUN_TEST(test_ft_atol_invalid);
	return (0);
}
