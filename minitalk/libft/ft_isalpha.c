/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:35:26 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/01 00:13:58 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (2);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main()
{
	printf("%d\n", isalpha('a'));
	printf("%d", ft_isalpha('a'));
}*/
