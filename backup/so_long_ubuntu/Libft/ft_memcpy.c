/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:21:31 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 19:27:42 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	size_t		i;
	char		*tdst;
	char		*tsrc;

	if ((dst == 0) && (src == 0))
		return (0);
	i = 0;
	tdst = (char *)dst;
	tsrc = (char *)src;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		i++;
	}
	return ((void *)tdst);
}
/*
#include <stdio.h>

int main(void)
{
	char a[] = "123456789";
	void *b = memcpy(a + 1, a, 5);
	void *c = ft_memcpy(a + 1, a, 5);
	int	i;

	i = 0;
	while(a[i])
	{
		printf("%c", *(char *)b++);
		i++;
	}
	printf("\n");
	i = 0;
	while (a[i])
	{
		printf("%c", *(char *)c++);
		i++;
	}
	printf("end");
}*/
