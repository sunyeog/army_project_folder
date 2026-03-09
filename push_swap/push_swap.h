#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648 
#include "libft/libft.h"

typedef struct s_node t_node;

struct s_node
{
    int data;
    t_node *prev;
    t_node *next;
} ;

typedef struct s_point
{
    t_node  *top;
    t_node  *bottom;
    int     size;
} t_point;

void	sa(t_point *stack_A);
void	sb(t_point *stack_B);
void	ss(t_point *stack_A, t_point *stack_B);
void	pa(t_point *stack_A, t_point *stack_B);
void	pb(t_point *stack_A, t_point *stack_B);
void    ra(t_point *stack_A);
void    rb(t_point *stack_B);
void    rr(t_point *stack_A, t_point *stack_B);
void    rra(t_point *stack_A);
void    rrb(t_point *stack_B);
void    rrr(t_point *stack_A, t_point *stack_B);
void    push(t_point *p, int d);
void    pop(t_point *p);
void    error(void);
void    check_int(char av[]);
void	check_mxmn(long long int result, int pl);
void	ft_long_atoi(t_point *stack_A, char *str);
t_point *l_init(void);

#endif