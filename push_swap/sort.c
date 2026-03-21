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
            if (mv_cur -> data < stop_cur -> data)
                index++;
            mv_cur = mv_cur -> next;
        }
        arr[i] = index;
        stop_cur = stop_cur -> next;
        i++;
    }
}

void to_index_stack(t_point *stack_A)
{
    int i;
    int *arr;
    t_node *cur;
    
    i = 0;
    cur = stack_A -> top;
    arr = (int *)malloc(sizeof(int) * stack_A -> size);
    if (arr == NULL)
        error();
    insert_index(stack_A, arr);
    while (cur != NULL)
    {
        cur -> data = arr[i];
        cur = cur -> next;
        i++;
    }
    free(arr);
}

void    radix_sort(t_point *stack_A, t_point *stack_B)
{
    int i;
    int j;
    int len;
    int sign;

    to_index_stack(stack_A);
    i = 0;
    len = stack_A -> size;
    while (i < 32)
    {
        sign = 0;
        j = 0;
        while (j < len)
        {
            if (!((stack_A -> top -> data >> i) & 1))
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

void    chunk_sort(t_point *stack_A, t_point *stack_B, int chunk)
{
    int i;
    int size;
    int range;

    to_index_stack(stack_A);
    size = stack_A -> size;
    i = 0;
    while (i < size % chunk)
    {
        if (stack_A -> top -> data < size % chunk)
        {
            pb(stack_A, stack_B);
            i++;
        }
        else
            ra(stack_A, 1);
    }
    i = 0;
    int pb_cnt;
    range = size / chunk + size % chunk;//한 덩어리마다 확인하는 인덱스 범위
    size = stack_A -> size;
    while (i < chunk)
    {
        if (chunk > size)
            break;
        pb_cnt = 0;
        while (pb_cnt < (size / chunk))
        {
            if (stack_A -> top -> data < range)
            {
                pb(stack_A, stack_B);
                pb_cnt++;
            }
            else
                ra(stack_A, 1);
        }
        range += (size / chunk);
        i++;
    }

    t_node *cur;
    int loc;
    while (stack_B -> top != NULL)
    {
        loc = 0;
        size = stack_B -> size;
        cur = stack_B -> top;
        while (cur -> data != size - 1)
        {
            loc++;
            cur = cur -> next;
        }
        while (stack_B -> top -> data != size - 1)
        {
            if (loc > (size / 2))
                rrb(stack_B, 1);
            else
                rb(stack_B, 1);
        }
        pa(stack_A,stack_B);
    }
}