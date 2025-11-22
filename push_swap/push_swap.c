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
    int     size;
} t_point;

t_point *l_init(void)// header 생성 및 초기화
{
    t_point *p = (t_point *)malloc(sizeof(t_point));
    
    p->top = (t_node *)malloc(sizeof(t_node));
    p->top->next = NULL;
    p->size = 0;
    return (p);
}

void  pop(t_point *p)
{
    t_node *temp = p->top;
    p->top = p->top->next;
    free(temp);
    p->size--;
}

void    F_push(t_point *p, int d)//첫 노드생성 후 값 삽입
{
    p->top->data = d;
    p->size++;
}

void    push(t_point *p, int d)//첫 노드 이후 값들 연결
{
    t_node  *new = (t_node  *)malloc(sizeof(t_node));
    new->data = d;
    new->next = p->top;
    p->top = new;
    p->size++;
}

int main(int ac, char **av)
{
    t_point *stack_A;
    // t_point *stack_B;
    int value;

    stack_A = l_init();
    // stack_B = l_init();
    value = ft_atoi(av[ac - 1]);
    F_push(stack_A, value);

    int i = 0;
    while (i < ac - 2)
    {
        value = ft_atoi(av[ac - 2 - i]);
        push(stack_A, value);
        i++;
    }



    
    i = 0;
    t_node *cur = stack_A->top;
    while (i < ac - 1)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("size : %d\n", stack_A->size);
    pop(stack_A);
    ft_printf("-------------------\n");
    i = 0;
    cur = stack_A->top;
    while (i < ac - 2)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("size : %d\n", stack_A->size);
    pop(stack_A);
    ft_printf("-------------------\n");
    i = 0;
    cur = stack_A->top;
    while (i < ac - 3)
    {
        ft_printf("%d\n" , cur->data);
        cur = cur->next;
        i++;
    }
    ft_printf("size : %d\n", stack_A->size);

    // ft_printf("%d\n", p->top->data);
    // ft_printf("%d\n", p->cur->data);
    // ft_printf("%d\n", ac);
    return 0;

    // av[0][0] = 0;
    // len = ac;
    // ft_printf("%d\n", len);
    // return 0;
}