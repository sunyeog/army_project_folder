#include "push_swap.h"

void    size_is_2(t_point *stack_A)
{
    if (stack_A -> top -> data > stack_A -> bottom -> data)
    {    
        sa(stack_A);
        ft_printf("sa\n");
    }
}

void    size_is_3(t_point *stack_A)