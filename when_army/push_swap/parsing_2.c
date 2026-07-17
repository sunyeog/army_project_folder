/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:16 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/09 16:34:37 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**to_new_arr(char **av)
{
	char	**res;
	int		len;

	len = return_split_len(av);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (res == NULL)
		error();
	res = fill_arr(av, res);
	res[len] = NULL;
	return (res);
}

void	check_int(char av[], char **arr, t_point *a, t_point *b)
{
	int	i;

	i = 1;
	if (!((av[0] >= '0' && av[0] <= '9') || av[0] == '+' || av[0] == '-'))
		error_free(arr, a, b);
	if ((av[0] == '+' || av[0] == '-') && av[1] == '\0')
		error_free(arr, a, b);
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			error_free(arr, a, b);
		i++;
	}
}

void	check_mxmn(long long int result, char **arr, t_point *a, t_point *b)
{
	if (result > INT_MAX || result < INT_MIN)
		error_free(arr, a, b);
}

void	long_atoi(t_point *stack_A, char *str, char **arr, t_point *stack_B)
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
		check_mxmn(result * negative, arr, stack_A, stack_B);
		str++;
	}
	result *= negative;
	push(stack_A, (int)result);
}

void	check_dup(t_point *stack_A, char **arr, t_point *stack_B)
{
	t_node	*i;
	t_node	*j;

	i = stack_A -> top;
	while (i != NULL)
	{
		j = i -> next;
		while (j != NULL)
		{
			if (i -> data == j -> data)
				error_free(arr, stack_A, stack_B);
			j = j -> next;
		}
		i = i -> next;
	}
}
