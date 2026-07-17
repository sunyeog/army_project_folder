/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:41:38 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/24 13:42:00 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	if (size != 0 && ((nmemb * size) / size != nmemb))
		return (0);
	temp = malloc(nmemb * size);
	if (temp == 0)
		return (0);
	ft_bzero(temp, (nmemb * size));
	return (temp);
}
/*
#include <stdio.h>

int main()
{
	void *a = ft_calloc(4,4);
	printf("%d", (size_t *)a);
}*/
