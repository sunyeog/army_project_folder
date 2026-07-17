/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:29:27 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 19:08:23 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mkmal(int n, int neg)
{
	char			*temp;
	long long int	i;
	int				power;

	power = 0;
	i = 1;
	while (i <= (long long int)n)
	{
		i *= 10;
		power++;
	}
	if (n == 0)
		power = 1;
	if (neg != -1)
		temp = (char *)malloc(sizeof(char) * (power + 1));
	else
	{
		temp = (char *)malloc(sizeof(char) * (power + 2));
		power += 1;
	}
	if (!temp)
		return (NULL);
	temp[power] = '\0';
	return (temp);
}

static void	extraction(int n, char *temp, int neg)
{
	long long int	x;
	int				y;
	int				res;
	int				i;

	i = 0;
	x = 1;
	while (x <= n)
		x *= 10;
	if (neg == -1)
		i = 1;
	while (x >= 10)
	{
		y = x / 10;
		res = n % x;
		res = res / y;
		temp[i] = res + '0';
		x /= 10;
		i++;
	}
	if (n == 0)
		temp[i] = '0';
}

static char	*if_min(char *temp)
{
	temp = ft_strdup("-2147483648");
	return (temp);
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		neg;

	neg = 1;
	if ((n < 0) && (n != -2147483648))
	{
		neg = -1;
		n *= -1;
	}
	temp = ft_mkmal(n, neg);
	if (!temp)
		return (NULL);
	if (n == 0)
	{
		extraction(n, temp, neg);
		return (temp);
	}
	else if (n == -2147483648)
		return (if_min(temp));
	else
	{
		temp[0] = '-';
		extraction(n, temp, neg);
		return (temp);
	}	
}
/*
#include <stdio.h>

int main(void)
{
	char *t = ft_itoa(-2147483648LL);
	printf("%s\n", t);
}*/
