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
    t_point *p;

    p = (t_point *)malloc(sizeof(t_point));
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

void    push(t_point *p, int d)
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
    //t_point *stack_B;

    stack_A = l_init();
    //stack_B = l_init();
    parsing(stack_A, av);

    int i;
    
    i = 0;
    t_node *cur = stack_A->top;
    while (i < ac - 1)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("-----------------------------\n");
   
    size_is_3(stack_A);
    
    i = 0;
    cur = stack_A->top;
    while (i < ac - 1)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("size : %d\n", stack_A->size);
    
    
    
    
    return 0;
}
