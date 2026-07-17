/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:33 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/03/25 13:35:35 by sunhnoh          ###   ########.fr       */
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
	while (arr[i])
	{
		check_int(arr[len - 1 - i]);
		long_atoi(stack_A, arr[len - 1 - i]);
		i++;
	}
	check_dup(stack_A);
	split_free(arr);
}
