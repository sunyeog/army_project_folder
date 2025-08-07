/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:41:00 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/03/24 14:31:27 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sep_test(char a, char c)
{
	if (a == c)
		return (1);
	if (a == '\0')
		return (1);
	return (0);
}

static char	**ft_isnul(char **res, int cnt)
{
	if (res[cnt] == NULL)
	{
		while (--cnt)
			free(res[cnt]);
		free(res);
		res = NULL;
	}
	return (res);
}

static void	fill_malloc(char *s, char c, char *res)
{
	int	i;

	i = 0;
	while (sep_test(s[i], c) == 0)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
}

static void	save_malloc(const char *s, char c, char **res)
{
	int		i;
	int		j;
	int		cnt;
	char	*tmp;

	tmp = (char *)s;
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (sep_test(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (sep_test(s[i + j], c) == 0)
				j++;
			res[cnt] = (char *)malloc(sizeof(char) * (j + 1));
			if (! ft_isnul(res, cnt))
				return ;
			fill_malloc(tmp + i, c, res[cnt]);
			i = i + j;
			cnt++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	int		i;
	char	**res;

	if (s == NULL)
		return (NULL);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (sep_test(s[i + 1], c) == 1
			&& sep_test(s[i], c) == 0)
			cnt++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (res == NULL)
		return (NULL);
	res[cnt] = 0;
	save_malloc(s, c, res);
	return (res);
}
/*
#include <stdio.h>

int main(void)
{
	char **res;
	int	i = 0;
	res = ft_split("      split       this for   me  !       ", ' ');
	while (res[i])
		printf("%s\n", res[i++]);
}*/
