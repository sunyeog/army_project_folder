#include "push_swap.h"

void    size_is_2(t_point *stack_A)
{
    if (stack_A -> top -> data > stack_A -> bottom -> data)
        sa(stack_A, 1);
}

void    size_is_3(t_point *stack_A)
{
    int top;
    int mid;
    int bot;

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

