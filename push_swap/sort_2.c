/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:28:18 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/12 13:28:19 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_index(t_point *stack_A, int *arr)
{
	t_node	*stop_cur;
	t_node	*mv_cur;
	int		index;
	int		i;

	i = 0;
	stop_cur = stack_A -> top;
	while (i < stack_A -> size)
	{
		index = 0;
		mv_cur = stack_A -> top;
		while (mv_cur != NULL)
		{
			if (mv_cur -> data < stop_cur -> data)
				index++;
			mv_cur = mv_cur -> next;
		}
		arr[i] = index;
		stop_cur = stop_cur -> next;
		i++;
	}
}

void	to_index_stack(t_point *stack_A)
{
	int		i;
	int		*arr;
	t_node	*cur;

	i = 0;
	cur = stack_A -> top;
	arr = (int *)malloc(sizeof(int) * stack_A -> size);
	if (arr == NULL)
		error();
	insert_index(stack_A, arr);
	while (cur != NULL)
	{
		cur -> data = arr[i];
		cur = cur -> next;
		i++;
	}
	free(arr);
}
