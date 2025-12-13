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

void	sa(t_point *stack_A)
{
    int temp;

    if (stack_A -> size < 2)
        return;
    temp = stack_A -> top -> data;
    stack_A -> top -> data = stack_A -> top -> next -> data;
    stack_A -> top -> next -> data = temp;
}

void	sb(t_point *stack_B)
{
    int temp;
    
    if (stack_B -> size < 2)
        return;
    temp = stack_B -> top -> data;
    stack_B -> top -> data = stack_B -> top -> next -> data;
    stack_B -> top -> next -> data = temp;
}

void	ss(t_point *stack_A, t_point *stack_B)
{
    sa(stack_A);
    sb(stack_B);
}

void	pa(t_point *stack_A, t_point *stack_B)
{
    if (stack_B -> size == 0)
        return;
    push(stack_A, stack_B->top->data);
    pop(stack_B);
}

void	pb(t_point *stack_A, t_point *stack_B)
{
    if (stack_A -> size == 0)
        return;
    push(stack_B, stack_A->top->data);
    pop(stack_A);
}

void    ra(t_point *stack_A)
{
    if (stack_A -> size == 0 || stack_A -> size == 1)
        return;
    t_node *temp;

    temp = stack_A -> top;
    stack_A -> top = stack_A -> top -> next;
    stack_A -> bottom -> next = temp;
    stack_A -> bottom = stack_A -> bottom -> next;
    stack_A -> bottom -> next = NULL;
}

void    rb(t_point *stack_B)
{
    if (stack_B -> size == 0 || stack_B -> size == 1)
        return;
    t_node *temp;

    temp = stack_B -> top;
    stack_B -> top = stack_B -> top -> next;
    stack_B -> bottom -> next = temp;
    stack_B -> bottom = stack_B -> bottom -> next;
    stack_B -> bottom -> next = NULL;
}

void    rr(t_point *stack_A, t_point *stack_B) 
{
    ra(stack_A);
    rb(stack_B);
}

void    rra(t_point *stack_A)
{
    if (stack_A -> size == 0 || stack_A -> size == 1)
        return;
    
    stack_A -> bottom -> next = stack_A -> top;
    stack_A -> top -> prev = stack_A -> bottom;
    stack_A -> top = stack_A -> bottom;
    stack_A -> bottom = stack_A -> bottom -> prev;
    stack_A -> bottom -> next = NULL;
    stack_A -> top -> prev = NULL;
    return;
}

void    rrb(t_point *stack_B)
{
    if (stack_B -> size == 0 || stack_B -> size == 1)
        return;
    
    stack_B -> bottom -> next = stack_B -> top;
    stack_B -> top -> prev = stack_B -> bottom;
    stack_B -> top = stack_B -> bottom;
    stack_B -> bottom = stack_B -> bottom -> prev;
    stack_B -> bottom -> next = NULL;
    stack_B -> top -> prev = NULL;
    return;
}

void    rrr(t_point *stack_A, t_point *stack_B)
{
    rra(stack_A);
    rrb(stack_B);
}