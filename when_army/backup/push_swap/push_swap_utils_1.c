/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:35:53 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/03/25 13:35:57 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_point *stack_A, int opt)
{
	int	temp;

	if (stack_A -> size < 2)
		return ;
	temp = stack_A -> top -> data;
	stack_A -> top -> data = stack_A -> top -> next -> data;
	stack_A -> top -> next -> data = temp;
	if (opt == 1)
		ft_printf("sa\n");
}

void	sb(t_point *stack_B, int opt)
{
	int	temp;

	if (stack_B -> size < 2)
		return ;
	temp = stack_B -> top -> data;
	stack_B -> top -> data = stack_B -> top -> next -> data;
	stack_B -> top -> next -> data = temp;
	if (opt == 1)
		ft_printf("sb\n");
}

void	ss(t_point *stack_A, t_point *stack_B)
{
	sa(stack_A, 0);
	sb(stack_B, 0);
	ft_printf("ss\n");
}
