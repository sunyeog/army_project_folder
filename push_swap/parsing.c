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

int dup(chat **av)
{
    
}

int parcing(int ac, char **av)
{
    if (ac < 1)
        return (0);
    
}