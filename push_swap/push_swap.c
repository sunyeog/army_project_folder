#include "push_swap.h"

typedef struct s_node
{
    int data;
    t_node *next;
} t_node;

typedef struct s_point
{
    t_node  *head;
    t_node  *cur;
    t_node  *tail;
    int     len;
} t_point;

void    l_init(t_point *p)
{
    p->head = (t_node   *)malloc(sizeof(t_node));
    p->head->next = NULL;
    p->len = 0;
}

void    Finsert(t_point *p, int d)
{
    t_node  *new = (t_node  *)malloc(sizeof(t_node));
    new->data = d;
    p->next = new;
    new->next = NULL;
}

int main(int ac, char **av)
{

    // av[0][0] = 0;
    // len = ac;
    // ft_printf("%d\n", len);
    // return 0;
}