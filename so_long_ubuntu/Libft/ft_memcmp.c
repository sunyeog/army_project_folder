/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:56:50 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/24 14:10:38 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((*ts1 == *ts2) && ((i + 1) < n))
	{
		ts1++;
		ts2++;
		i++;
	}
	return (*ts1 - *ts2);
}
/*
#include <stdio.h>

int main(void)
{
    char *a = "abhrw";
    char *b = "achrd";
    printf("%d", ft_memcmp(b, a, 2));
}*/
