/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:52:55 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 17:10:51 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tsrc;
	char	*tdst;
	size_t	i;

	if ((dst == 0) && (src == 0))
		return (0);
	i = 0;
	tsrc = (char *)src;
	tdst = (char *)dst;
	if (dst > src)
	{
		while (len--)
			*(tdst + len) = *(tsrc + len);
	}
	else
	{
		while (len--)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>

int main(void)
{
	char a[] = "123456789";
	char d[] = "123456789";
	//void *b = memmove(a + 1, a, 5);
	//void *c = ft_memmove(d + 1, d, 5);
	printf("%s", (char *)memmove(a, a + 1, 5));
	printf("\n");
	printf("%s", (char *)ft_memmove(d, d + 1, 5));
	printf("\n");
	printf("end");
}*/
