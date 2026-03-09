/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:29:27 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 19:08:23 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_mxmn(long long int result, int pl)
{
	long long int sign;

	sign = result * pl;
	if (sign > INT_MAX || sign < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
}

int	ft_long_atoi(const char *str)
{
	long long int	negative;
	long long int	result;

	result = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		check_mxmn(result, negative);
		str++;
	}
	result *= negative;
	return ((int)result);
}