#include "push_swap.h"

int check_int(char av[])
{
    int i;

    i = 1;
    if (!((av[0] >= '0' && av[0] <= '9') || av[0] == '+' || av[0] == '-'))
        return (0);
    while(av[i])
    {
        if (!(av[i] >= '0' && av[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

void	check_mxmn(long long int result, int pl)
{
	long long int sign;

	sign = result * pl;
	if (sign > INT_MAX || sign < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
}

void	ft_long_atoi(t_point *stack_A, char *str)
{
	long long int	negative;
	long long int	result;

	result = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		check_mxmn(result, negative);
		str++;
	}
	result *= negative;
	push(stack_A, (int)result);
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

int parcing(int ac, char **av)
{
    if (ac < 1)
        return (0);
    
}