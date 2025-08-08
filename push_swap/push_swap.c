#include "push_swap.h"

typedef struct s_stack
{
    int *arr;
    int top;
    int size;
} t_stack;

t_stack *mk_structA(int ac, char **av)
{
    int i;
    t_stack *a;

    i = 0;
    a = malloc(sizeof(t_stack));
    a->arr = malloc(sizeof(int) * ac - 1);
    while(av[i])
    {
        a->arr[i] = ft_atoi(av[i + 1])
        i++;
    }
    a->top = a->arr[0];
    a->size = ac - 1;
    return (a);
}

t_stack *mk_structB(int ac, char **av)
{
    t_stack *b;

    b = malloc(sizeof(t_stack));
    b->top = b->arr[0];
    b->size = ac - 1;
    return (b);
}


int main(int ac, char **av)
{
    int len;

    t_stack *a;
    t_stack *b;

    a = mk_structA(ac, av);
    b = mk_structB(ac, av);

    av[0][0] = 0;
    len = ac;
    ft_printf("%d\n", len);
    return 0;
}