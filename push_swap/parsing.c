#include "push_swap.h"

void    split_free(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int parcing(int ac, char **av)
{
    if (ac < 1)
        return (0);
    
}