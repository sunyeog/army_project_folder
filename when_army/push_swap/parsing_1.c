/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:32:51 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/12 16:16:29 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_free(char **arr, t_point *stack_a, t_point *stack_b)
{
	if (arr != NULL)
		split_free(arr);
	if (stack_a != NULL)
		free_stack(stack_a, stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	split_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	return_split_len(char **av)
{
	int		i;
	int		j;
	int		len;
	char	**res;

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
	int		i;
	int		j;
	int		index;
	char	**temp;

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
