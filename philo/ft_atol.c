/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 14:49:12 by thfernan          #+#    #+#             */
/*   Updated: 2026/06/17 19:45:18 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
			sign = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str != '\0')
		return (0);
	if ((sign == 1 && result > 2147483647)
		|| (sign == -1 && result > 2147483648u))
		return (0);
	return (result * sign);
}
