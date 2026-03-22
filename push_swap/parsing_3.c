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

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	parsing(t_point *stack_A, char **av)
{
	int		i;
	int		len;
	char	**arr;

	i = 0;
	arr = to_new_arr(av);
	len = arr_len(arr);
	check_dup(arr);
	while (arr[i])
	{
		check_int(arr[len - 1 - i]);
		long_atoi(stack_A, arr[len - 1 - i]);
		i++;
	}
	split_free(arr);
}
