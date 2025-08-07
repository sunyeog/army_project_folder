#include "push_swap.h"

typedef struct s_stack
{
    int *arr;
    int top;
    int size;
} t_stack;

int *mk_stackA(int ac, char **av)
{
    int *arr;
    int i;

    i = 0;
    arr = (int *)malloc(sizeof(int) * ac - 1);
    while(av[i])
    {
        arr[i] = ft_atoi(av[i + 1])
        i++;
    }
    return (arr);
}

int *mk_stackB(int ac, char **av)
{
    int *arr;

    arr = (int *)malloc(sizeof(int) * ac - 1);
    return (arr);
}

void
int main(int ac, char **av)
{
    int len;

    t_stack a;
    t_stack b;
    
    a.arr = mk_stackA(ac, av);
    b.arr = mk_stackB(ac, av);

    
    av[0][0] = 0;
    len = ac;
    ft_printf("%d\n", len);
    return 0;
}