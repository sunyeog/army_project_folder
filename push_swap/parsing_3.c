/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:33 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/12 14:19:35 by sunhnoh          ###   ########.fr       */
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

int	if_already_sort(t_point *stack_A)
{
	int		i;
	int		cnt;
	t_node	*cur;

	i = 0;
	cnt = 0;
	cur = stack_A -> top;
	while (i < stack_A -> size - 1)
	{
		if (cur -> data + 1 != cur -> next -> data)
			cnt++;
		cur = cur -> next;
		i++;
	}
	if (cnt == 0)
		return (0);
	else
		return (1);
}

int	parsing(t_point *stack_A, t_point *stack_B, int ac, char **av)
{
	int		i;
	int		len;
	char	**arr;

	i = 0;
	arr = to_new_arr(av);
	len = arr_len(arr);
	while (arr[i])
	{
		check_int(arr[len - 1 - i], arr, stack_A, stack_B);
		long_atoi(stack_A, arr[len - 1 - i], arr, stack_B);
		i++;
	}
	check_dup(stack_A, arr, stack_B);
	split_free(arr);
	to_index_stack(stack_A);
	if (if_already_sort(stack_A) == 0)
	{
		free_stack(stack_A, stack_B);
		(void)ac;
		return (0);
	}
	else
		return (1);
}
