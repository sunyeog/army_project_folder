#include "push_swap.h"

typedef struct s_node t_node;

struct s_node
{
    int data;
    t_node *next;
} ;

typedef struct s_point
{
    t_node  *top;
    int     len;
} t_point;

t_point *l_init(void)// header 생성 및 초기화
{
    t_point *p = (t_point *)malloc(sizeof(t_point));
    
    p->top = (t_node   *)malloc(sizeof(t_node));
    p->top = NULL;
    p->len = 0;
    return (p);
}

void  pop(t_point *p)
{
    t_node *temp = p->top;
    p->top = p->top->next;
    free(temp);
}

void    Finsert(t_point *p, int d)//첫 노드생성 후 값 삽입
{
    t_node  *new = (t_node  *)malloc(sizeof(t_node));
    new->data = d;
    p->top = new;
    new->next = NULL;
}

void    push(t_point *p, int d)//첫 노드 이후 값들 연결
{
    t_node  *new = (t_node  *)malloc(sizeof(t_node));
    new->data = d;
    new->next = p->top;
    p->top = new;
}

int main(int ac, char **av)
{
    t_point *p;
    int value;

    p = l_init();
    value = ft_atoi(av[ac - 1]);
    Finsert(p, value);

    int i = 0;
    while (i < ac - 2)
    {
        value = ft_atoi(av[ac - 2 - i]);
        push(p, value);
        i++;
    }
    i = 0;
    while (i < ac - 1)
    {
        ft_printf("%d\n" , p->top->data);
        p->top = p->top->next;
        i++;
    }
    pop(p);
    i = 0;
    t_node *cur = p->top;
    while (i < ac - 2)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }

    // ft_printf("%d\n", p->top->data);
    // ft_printf("%d\n", p->cur->data);
    // ft_printf("%d\n", ac);
    return 0;

    // av[0][0] = 0;
    // len = ac;
    // ft_printf("%d\n", len);
    // return 0;
}