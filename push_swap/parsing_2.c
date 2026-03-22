/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosunhyeog <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:25:06 by nosunhyeog        #+#    #+#             */
/*   Updated: 2024/03/22 19:36:26 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char av[])
{
	int	i;

	i = 1;
	if (!((av[0] >= '0' && av[0] <= '9') || av[0] == '+' || av[0] == '-'))
		error();
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			error();
		i++;
	}
}

void	check_mxmn(long long int result, int neg)
{
	long long int	sign;

	sign = result * neg;
	if (sign > INT_MAX || sign < INT_MIN)
		error();
}

void	long_atoi(t_point *stack_A, char *str)
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
	push(stack_A, (int)result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	i = 0;
	while ((a[i] == b[i]) && (a[i] && b[i]))
		i++;
	return (a[i] - b[i]);
}

void	check_dup(char **arr)
{
	int	i;
	int	j;
	int	dup_cnt;

	i = 0;
	while (arr[i])
	{
		dup_cnt = 0;
		j = 0;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) == 0)
			{
				dup_cnt++;
				if (dup_cnt == 2)
					error();
			}
			j++;
		}
		i++;
	}
}
