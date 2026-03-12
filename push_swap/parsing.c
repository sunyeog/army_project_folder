#include "push_swap.h"

void    error(void)
{
	ft_printf("Error\n");
	exit(1);
}

//----------------------------------------

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

//----------------------------------------

int	return_split_len(char **av)
{
	int	i;
	int	j;
	int	len;
	char **res;

	i = 1;
	len = 0;
	while (av[i])
	{
		res = ft_split(av[i], ' ');
		j = 0;
		while (res[j])
		{
			len++;
			j++;
		}
		split_free(res);
		i++;
	}
	return (len);
}

char	**fill_arr(char **av, char **res)
{
	int	i;
	int	j;
	int	index;
	char **temp;

	i = 1;
	index = 0;
	while (av[i])
	{
		temp = ft_split(av[i], ' ');
		j = 0;
		while (temp[j])
		{
			res[index] = temp[j];
			index++;
			j++;
		}
		free(temp);
		i++;
	}
	return (res);
}

char	**to_new_arr(char **av)
{
	char **res;
	int len;

	len = return_split_len(av);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (res == NULL)
		error();
	res = fill_arr(av, res);
	res[len] = NULL;
	return (res);
}
//----------------------------------------

void check_int(char av[])
{
    int i;

    i = 1;
    if (!((av[0] >= '0' && av[0] <= '9') || av[0] == '+' || av[0] == '-'))
        error();
    while(av[i])
    {
        if (!(av[i] >= '0' && av[i] <= '9'))
            error();
        i++;
    }
}

//----------------------------------------

void	check_mxmn(long long int result, int neg)
{
	long long int sign;

	sign = result * neg;
	if (sign > INT_MAX || sign < INT_MIN)
        error();
}

void	long_atoi(t_point *stack_A, char *str)
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

//----------------------------------------

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	i = 0;
	while ((a[i] == b[i]) && (a[i] && b[i]))
		i++;
	return (a[i] - b[i]);
}

void	check_dup(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (i == j)
				j++;
			if (ft_strcmp(arr[i], arr[j]) == 0)
				error();
			j++;
		}
		i++;
	}
}

//----------------------------------------

void parsing(t_point *stack_A, char **av)
{
	int	i;
    char **arr = to_new_arr(av);

	check_dup(arr);
	i = 0;
	while (arr[i])
	{
		check_int(arr[i]);
		long_atoi(stack_A, arr[i]);
		i++;
	}
}