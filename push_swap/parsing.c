#include "push_swap.h"

int check_av(char *av)
{
    int i;
    int len;
    
    len = ft_strlen(av);
    i = 0;
    while (i < len)
    {
        if (av[i] == " ")
            return (1);
        i++;
    }
    return (0);
}

void    split_free(char **arr, int  len)
{
    int i;

    i = 0;
    while (i < len)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

 void   many_push(char *av)
 {
    char    **arr;
    int i;
    int len;

    arr = ft_split(av);
    i = 0;
    while (arr[i] != NULL)
        i++;
    len = i;
    i = 0;
    while (i < len)
    {
        push(stack_A, ft_atoi(arr[len - 1 - i]));
        i++;
    }
    split_free(arr, len);
 }

int dup(chat **av)
{
    
}

int parcing(int ac, char **av)
{
    if (ac < 1)
        return (0);
    
}