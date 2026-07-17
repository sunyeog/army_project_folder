/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:28:27 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/12 13:28:30 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rest_process(t_point *stack_A, t_point *stack_B, int chunk)
{
	int	i;
	int	size;

	size = stack_A -> size;
	i = 0;
	while (i < size % chunk)
	{
		if (stack_A -> top -> data < size % chunk)
		{
			pb(stack_A, stack_B);
			i++;
		}
		else
			ra(stack_A, 1);
	}
}

void	to_stack_b(t_point *stack_A, t_point *stack_B, int chunk, int range)
{
	int	pb_cnt;
	int	size;
	int	i;

	i = 0;
	size = stack_A -> size;
	while (i < chunk)
	{
		if (chunk > size)
			break ;
		pb_cnt = 0;
		while (pb_cnt < (size / chunk))
		{
			if (stack_A -> top -> data < range)
			{
				pb(stack_A, stack_B);
				pb_cnt++;
			}
			else
				ra(stack_A, 1);
		}
		range += (size / chunk);
		i++;
	}
}

void	to_stack_a(t_point *stack_A, t_point *stack_B)
{
	int		size;
	int		loc;
	t_node	*cur;

	while (stack_B -> top != NULL)
	{
		loc = 0;
		size = stack_B -> size;
		cur = stack_B -> top;
		while (cur -> data != size - 1)
		{
			loc++;
			cur = cur -> next;
		}
		while (stack_B -> top -> data != size - 1)
		{
			if (loc > (size / 2))
				rrb(stack_B, 1);
			else
				rb(stack_B, 1);
		}
		pa(stack_A, stack_B);
	}
}

void	chunk_sort(t_point *stack_A, t_point *stack_B, int chunk)
{
	int	size;
	int	range;

	size = stack_A -> size;
	rest_process(stack_A, stack_B, chunk);
	range = size / chunk + size % chunk;
	to_stack_b(stack_A, stack_B, chunk, range);
	to_stack_a(stack_A, stack_B);
}
