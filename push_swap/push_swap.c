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

t_point	*l_init(void)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	p -> top = NULL;
	p -> bottom = NULL;
	p->size = 0;
	return (p);
}

void	pop(t_point *p)
{
	t_node	*temp;

	if (p -> size == 0)
		return ;
	if (p -> size == 1)
	{
		free(p -> top);
		p -> top = NULL;
		p -> bottom = NULL;
		p -> size--;
		return ;
	}
	temp = p -> top;
	p -> top = p -> top -> next;
	p -> top -> prev = NULL;
	p -> size--;
	free(temp);
}

void	push(t_point *p, int d)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (p -> size == 0)
	{
		new -> data = d;
		p -> top = new;
		p -> bottom = new;
		new -> next = NULL;
		new -> prev = NULL;
		p -> size++;
		return ;
	}
	new -> data = d;
	new -> prev = NULL;
	new -> next = p -> top;
	p -> top -> prev = new;
	p -> top = new;
	p -> size++;
}

int	main(int ac, char **av)
{
	t_point	*stack_a;
	t_point	*stack_b;

	stack_a = l_init();
	stack_b = l_init();
	parsing(stack_a, av);
	if (stack_a -> size == 2)
		size_is_2(stack_a);
	else if (stack_a -> size == 3)
		size_is_3(stack_a);
	else if (stack_a -> size <= 100)
		chunk_sort(stack_a, stack_b, 5);
	else if (stack_a -> size <= 250)
		chunk_sort(stack_a, stack_b, 10);
	else
		chunk_sort(stack_a, stack_b, 14);
	if (ac == 0)
		return (0);
	return (0);
}
