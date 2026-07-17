/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:24:33 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/08/22 15:58:17 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sumlen(const char *s1, const char *s2)
{
	int	len1;
	int	len2;
	int	lensum;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	lensum = len1 + len2;
	return (lensum);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		lensum;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lensum = sumlen(s1, s2);
	temp = (char *)malloc(sizeof(char) * (lensum + 1));
	if (temp == 0)
		return (0);
	temp[lensum] = 0;
	while (s1[j])
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	free(s1);
	return (temp);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%s", ft_strjoin("abc", "defghij"));
}*/
