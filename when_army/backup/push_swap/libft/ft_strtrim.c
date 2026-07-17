/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:25:51 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/23 18:45:30 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_front(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				cnt++;
				break ;
			}
			j++;
			if (set[j] == '\0')
				return (cnt);
		}
		i++;
	}
	return (cnt);
}

static size_t	ft_back(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (s1[ft_strlen(s1) - i - 1])
	{
		j = 0;
		while (set[j])
		{
			if (s1[ft_strlen(s1) - i - 1] == set[j])
			{
				cnt++;
				break ;
			}
			j++;
			if (set[j] == '\0')
				return (cnt);
		}
		i++;
	}
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*tmp;
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(s1) - ft_back(s1, set) - ft_front(s1, set);
	if ((int)len < 0)
		return (ft_strdup(""));
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	tmp[len] = 0;
	while (i < len)
	{
		tmp[i] = s1[ft_front(s1, set) + i];
		i++;
	}
	return (tmp);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *str = ft_strtrim("asd123dsa", "asd");
	printf("%s\n", str);
}*/
