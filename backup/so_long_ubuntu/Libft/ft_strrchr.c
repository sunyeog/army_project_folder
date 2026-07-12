/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:38:44 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 17:20:32 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = 0;
	while (*s)
	{
		if (*s == c)
			temp = s;
		s++;
	}
	if (*s == c)
		temp = s;
	return ((char *)temp);
}
/*
#include <stdio.h>

int main(void)
{
	const char s[] = "abcdefgfg";
	int c = 'c';
	printf("%s", ft_strrchr(s, c));
}*/
