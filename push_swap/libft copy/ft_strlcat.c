/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:43:21 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 17:48:46 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idst;
	size_t	ldst;
	size_t	lsrc;
	size_t	isrc;

	if (size == 0)
		return (ft_strlen(src));
	idst = ft_strlen(dst);
	isrc = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	while (src[isrc] && (ldst + isrc + 1 < size))
	{
		dst[idst] = src[isrc];
		idst++;
		isrc++;
	}
	dst[idst] = 0;
	if (ldst < size)
		return (lsrc + ldst);
	else
		return (lsrc + size);
}
/*
#include <stdio.h>

int main()
{
	char	s1[] = "123456789";
	const char	s2[] = "hello";
	printf("%ld\n", ft_strlcat(s1,s2,5));
	//printf("%u", strlcat(s1,s2,10));
	return 0;
}*/
