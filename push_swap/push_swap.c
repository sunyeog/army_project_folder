#include "push_swap.h"

typedef struct s_node t_node;

struct s_node
{
    int data;
    t_node *next;
} ;

typedef struct s_point
{
    t_node  *head;
    t_node  *cur;
    t_node  *tail;
    int     len;
} t_point;

t_point *l_init(void)//header 생성 및 초기화
{
    t_point *p = (t_point *)malloc(sizeof(t_point));

    p->head = (t_node   *)malloc(sizeof(t_node));
    p->head->next = NULL;
    p->len = 0;
    return (p);
}

void    Finsert(t_point *p, int d)//첫 노드생성 후 값 삽입
{
    t_node  *new = (t_node  *)malloc(sizeof(t_node));
    new->data = d;
    p->head = new;
    p->tail = new;
    p->cur = new;
    new->next = NULL;
}

void    insert(t_point *p, int d)//첫 노드 이후 값들 연결
{
    t_node  *new = (t_node  *)malloc(sizeof(t_node));
    new->data = d;
    p->cur->next = new;
    p->cur = new;
    p->tail = new;
    new->next = NULL;
}



int main(int ac, char **av)
{
    t_point *p;
    int value;

    p = l_init();
    value = ft_atoi(av[1]);
    Finsert(p, value);
    int i;

    i = 0;
    while (i < ac - 1)
    
    ft_printf("%d\n", p->head->data);
    ft_printf("%d\n", ac);
    return 0;

    // av[0][0] = 0;
    // len = ac;
    // ft_printf("%d\n", len);
    // return 0;
}