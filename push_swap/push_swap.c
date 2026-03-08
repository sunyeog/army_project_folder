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

t_point *l_init(void)// header 생성 및 초기화
{
    t_point *p = (t_point *)malloc(sizeof(t_point));
    
    p -> top = NULL;
    p -> bottom = NULL;
    p->size = 0;
    return (p);
}

void  pop(t_point *p)
{
    if (p -> size == 0)
        return;
    if (p -> size == 1)
    {
        free(p -> top);
        p -> top = NULL;
        p -> bottom = NULL; 
        p -> size--;
        return;
    }
    t_node  *temp;

    temp = p -> top;
    p -> top = p -> top -> next;
    p -> top -> prev = NULL;
    free(temp);
    p -> size--;
}

void    push(t_point *p, int d)//첫 노드 이후 값들 연결
{
    t_node  *new;

    new = (t_node  *)malloc(sizeof(t_node));
    if (p -> size == 0)
    {
        new -> data = d;
        p -> top = new;
        p -> bottom = new;
        new -> next = NULL;
        new -> prev = NULL;
        p -> size++;
        return;
    }
    
    new -> data = d;
    new -> prev = NULL;
    new -> next = p -> top;
    p -> top -> prev = new;
    p -> top = new;
    p -> size++;
}

int main(int ac, char **av)
{
    t_point *stack_A;
    t_point *stack_B;
    int value;

    stack_A = l_init();
    stack_B = l_init();
    value = ft_atoi(av[ac - 1]);
    push(stack_A, value);

    int i = 0;
    while (i < ac - 2)
    {
        value = ft_atoi(av[ac - 2 - i]);
        push(stack_A, value);
        i++;
    }




    
    i = 0;
    t_node *cur = stack_A->top;
    while (i < ac - 1)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("size : %d\n", stack_A->size);
    pop(stack_A);
    ft_printf("-------------------\n");
    i = 0;
    cur = stack_A->top;
    while (i < ac - 2)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("size : %d\n", stack_A->size);
    pop(stack_A);
    ft_printf("-------------------\n");
    i = 0;
    cur = stack_A->top;
    while (i < ac - 3)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("size : %d\n", stack_A->size);
    ft_printf("top : %d\n", stack_A->top->data);
    ft_printf("bottom : %d\n", stack_A->bottom->data);
    
    rra(stack_A);
    sb(stack_B);
    ft_printf("-------------------\n");
    i = 0;
    cur = stack_A->top;
    while (i < ac - 3)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("size : %d\n", stack_A->size);
    ft_printf("top : %d\n", stack_A->top->data);
    ft_printf("bottom : %d\n", stack_A->bottom->data);
    

    // ft_printf("%d\n", p->top->data);
    // ft_printf("%d\n", p->cur->data);
    // ft_printf("%d\n", ac);
    return 0;

    // av[0][0] = 0;
    // len = ac;
    // ft_printf("%d\n", len);
    // return 0;
}
