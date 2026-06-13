/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 14:49:12 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/13 15:08:22 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philoshophers.h"

long long	ft_atol(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign == -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		if (result >= 2147483648 || result <= -2147483649)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
