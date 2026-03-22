/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosunhyeog <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:25:06 by nosunhyeog        #+#    #+#             */
/*   Updated: 2024/03/22 19:36:26 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_is_2(t_point *stack_A)
{
	if (stack_A -> top -> data > stack_A -> bottom -> data)
		sa(stack_A, 1);
}

void	size_is_3(t_point *stack_A)
{
	int	top;
	int	mid;
	int	bot;

	top = stack_A -> top -> data;
	mid = stack_A -> top -> next -> data;
	bot = stack_A -> bottom -> data;
	if ((top > mid) && (top > bot) && (mid > bot))
	{
		sa(stack_A, 1);
		rra(stack_A, 1);
	}
	else if ((top > mid) && (top > bot) && (mid < bot))
		ra(stack_A, 1);
	else if ((mid > top) && (mid > bot) && (top > bot))
		rra(stack_A, 1);
	else if ((mid > top) && (mid > bot) && (top < bot))
	{
		sa(stack_A, 1);
		ra(stack_A, 1);
	}
	else if ((bot > mid) && (bot > top) && (mid < top))
		sa(stack_A, 1);
}

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
