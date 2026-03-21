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

void	pa(t_point *stack_A, t_point *stack_B)
{
    if (stack_B -> size == 0)
        return;
    push(stack_A, stack_B->top->data);
    pop(stack_B);
    ft_printf("pa\n");
}

void	pb(t_point *stack_A, t_point *stack_B)
{
    if (stack_A -> size == 0)
        return;
    push(stack_B, stack_A->top->data);
    pop(stack_A);
    ft_printf("pb\n");
}

void    rra(t_point *stack_A, int opt)
{
    if (stack_A -> size == 0 || stack_A -> size == 1)
        return;
    
    stack_A -> bottom -> next = stack_A -> top;
    stack_A -> top -> prev = stack_A -> bottom;
    stack_A -> top = stack_A -> bottom;
    stack_A -> bottom = stack_A -> bottom -> prev;
    stack_A -> bottom -> next = NULL;
    stack_A -> top -> prev = NULL;
    if (opt == 1)
        ft_printf("rra\n");
}

void    rrb(t_point *stack_B, int opt)
{
    if (stack_B -> size == 0 || stack_B -> size == 1)
        return;
    
    stack_B -> bottom -> next = stack_B -> top;
    stack_B -> top -> prev = stack_B -> bottom;
    stack_B -> top = stack_B -> bottom;
    stack_B -> bottom = stack_B -> bottom -> prev;
    stack_B -> bottom -> next = NULL;
    stack_B -> top -> prev = NULL;
    if (opt == 1)
        ft_printf("rrb\n");
}

void    rrr(t_point *stack_A, t_point *stack_B)
{
    rra(stack_A, 0);
    rrb(stack_B, 0);
    ft_printf("rrr\n");
}