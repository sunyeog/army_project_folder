#include "push_swap.h"

int check_av(char *av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (av[i] == ' ')
            return (1);
        i++;
    }
    return (0);
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

int is_num(char **arr)
{
    int i;
    int j;

    i = 0;
    while (arr[i])
    {
        j = 0;
        while (arr[i][j])
        {
            if (ft_isalnum(arr[i][j]) == 1 || ft_isalnum(arr[i][j]) == 2)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int   if_many_arg(char *av)
{
    char    **arr;
    int i;
    int len;

    arr = ft_split(av, ' ');
    if (is_num(arr) == 0)
    {
        split_free(arr);
        return (0);
    }
    if (!arr || !arr[0])
        return (0);
    i = 0;
    len = 0;
    while (arr[len] != NULL)
        len++;
    while (i < len)
    {
        push(stack_A, ft_atoi(arr[len - 1 - i]));
        i++;
    }
    split_free(arr);
}

int dup(chat **av)
{
    
}

int parcing(int ac, char **av)
{
    if (ac < 1)
        return (0);
    
}