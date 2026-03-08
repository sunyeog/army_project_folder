#include "push_swap.h"

int check_int(char av[])
{
    int i;

    i = 1;
    if (!((av[0] >= '0' && av[0] <= '9') || av[0] == '+' || av[0] == '-'))
        return (0);
    while(av[i])
    {
        if (!(av[i] >= '0' && av[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int check_range(char av[])
{
    //------------------START
}

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