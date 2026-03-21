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

void	sa(t_point *stack_A, int opt);
void	sb(t_point *stack_B, int opt);
void	ss(t_point *stack_A, t_point *stack_B);
void	pa(t_point *stack_A, t_point *stack_B);
void	pb(t_point *stack_A, t_point *stack_B);
void    ra(t_point *stack_A, int opt);
void    rb(t_point *stack_B, int opt);
void    rr(t_point *stack_A, t_point *stack_B);
void    rra(t_point *stack_A, int opt);
void    rrb(t_point *stack_B, int opt);
void    rrr(t_point *stack_A, t_point *stack_B);
void    push(t_point *p, int d);
void    pop(t_point *p);
void    split_free(char **arr);
void    error(void);
void    check_int(char av[]);
void	check_mxmn(long long int result, int pl);
void	long_atoi(t_point *stack_A, char *str);
int return_split_len(char **av);
char	**fill_arr(char **av, char **res);
char	**to_new_arr(char **av);
int ft_strcmp(char *s1, char *s2);
void	check_dup(char **arr);
int arr_len(char **arr);
void    parsing(t_point *stack_A, char **av);
void    size_is_2(t_point *stack_A);
void    size_is_3(t_point *stack_A);
void    insert_index(t_point *stack_A, int *arr);
void    to_index_stack(t_point *stack_A);
void    radix_sort(t_point *stack_A, t_point *stack_B);
void    chunk_sort(t_point *stack_A, t_point *stack_B, int div);
t_point *l_init(void);

#endif