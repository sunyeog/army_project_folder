/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:18:30 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/06/28 01:26:52 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		((unsigned char *)ptr)[i] = value;
		if (((unsigned char *)ptr)[i] != value)
			return (0);
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>

int main(void)
{
	int	i;

	i = 0;
	unsigned char a[] = "023456789";
	unsigned char *n = ft_memset(a, '1', 8);
	unsigned char *m = memset(a, '1', 8);
	while (n[i])
	{
		printf("%c", n[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (n[i])
	{
		printf("%c", m[i]);
		i++;
	}
}*/
