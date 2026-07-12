/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:37:27 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/12 14:20:25 by sunhnoh          ###   ########.fr       */
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

int	find_lowest_index(t_point	*stack_A)
{
	int		i;
	int		res_i;
	int		res_value;
	t_node	*cur;

	i = 1;
	res_i = 0;
	res_value = stack_A -> top -> data;
	cur = stack_A -> top -> next;
	while (i < stack_A -> size)
	{
		if (res_value > cur -> data)
		{
			res_value = cur -> data;
			res_i = i;
		}	
		cur = cur -> next;
		i++;
	}
	return (res_i);
}

void	pb_lowest(t_point *stack_A, t_point *stack_B)
{
	int	i;
	int	pos;

	i = 0;
	pos = find_lowest_index(stack_A);
	if (pos > (stack_A -> size / 2))
	{
		while (i < stack_A -> size - pos)
		{
			rra(stack_A, 1);
			i++;
		}
	}
	else
	{
		while (i < pos)
		{
			ra(stack_A, 1);
			i++;
		}
	}
	pb(stack_A, stack_B);
}

void	size_is_5(t_point *stack_A, t_point *stack_B)
{
	if (stack_A -> size == 4)
	{
		pb_lowest(stack_A, stack_B);
		size_is_3(stack_A);
		pa(stack_A, stack_B);
	}
	else
	{
		pb_lowest(stack_A, stack_B);
		pb_lowest(stack_A, stack_B);
		size_is_3(stack_A);
		pa(stack_A, stack_B);
		pa(stack_A, stack_B);
	}
}
