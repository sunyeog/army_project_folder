/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:22:34 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 14:28:24 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (temp == 0)
		return (0);
	temp[ft_strlen(s)] = 0;
	while (s[i])
	{
		temp[i] = (*f)(i, s[i]);
		i++;
	}
	return (temp);
}
