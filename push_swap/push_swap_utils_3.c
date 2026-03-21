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

void    ra(t_point *stack_A, int opt)
{
    if (stack_A -> size == 0 || stack_A -> size == 1)
        return;
    t_node *temp;

    temp = stack_A -> top;
    stack_A -> top = stack_A -> top -> next;
    stack_A -> bottom -> next = temp;
    temp -> prev = stack_A -> bottom;
    stack_A -> bottom = temp;
    stack_A -> bottom -> next = NULL;
    stack_A -> top -> prev = NULL;
    if (opt == 1)
        ft_printf("ra\n");
}

void    rb(t_point *stack_B, int opt)
{
    if (stack_B -> size == 0 || stack_B -> size == 1)
        return;
    t_node *temp;

    temp = stack_B -> top;
    stack_B -> top = stack_B -> top -> next;
    stack_B -> bottom -> next = temp;
    temp -> prev = stack_B -> bottom;
    stack_B -> bottom = temp;
    stack_B -> bottom -> next = NULL;
    stack_B -> top -> prev = NULL;
    if (opt == 1)
        ft_printf("rb\n");
}

void    rr(t_point *stack_A, t_point *stack_B) 
{
    ra(stack_A, 0);
    rb(stack_B, 0);
    ft_printf("rr\n");
}