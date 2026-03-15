#include "push_swap.h"

void    size_is_2(t_point *stack_A)
{
    if (stack_A -> top -> data > stack_A -> bottom -> data)
        sa(stack_A, 1);
}

//-----------------------------------------

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

//-----------------------------------------

void insert_index(t_point *stack_A, int *arr)
{
    t_node *stop_cur;
    t_node *mv_cur;
    int index;
    int i;

    i = 0;
    stop_cur = stack_A -> top;
    while (i < stack_A -> size)
    {
        index = 0;
        mv_cur = stack_A -> top;
        while (mv_cur != NULL)
        {
            if (stop_cur -> data < mv_cur -> data)
                index++;
            mv_cur = mv_cur -> next;
        }
        arr[i] = index;
        stop_cur = stop_cur -> next;
        i++;
    }
}

int *to_index_arr(t_point *stack_A)
{
    int *arr;
    
    arr = (int *)malloc(sizeof(int) * stack_A -> size);
    if (arr == NULL)
        return (NULL);
    insert_index(stack_A, arr);
    
    return (arr);
}

void    radix_sort(t_point *stack_A, t_point *stack_B, int *arr)
{
    int i;
    int j;
    int sign;
    int len;

    i = 0;
    len = stack_A -> size;
    while (i < len)
    {
        j = 0;
        sign = 0;
        while (j < len)
        {
            if (!((arr[j] >> i) & 1))
                pb(stack_A, stack_B);
            else
            {
                ra(stack_A, 1);
                sign++;
            }
            j++;
        }
        while (stack_B -> top != NULL)
            pa(stack_A, stack_B);
        if (sign == 0)
            return;
        i++;
    }
}