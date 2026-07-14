/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:11:09 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/08/22 16:05:21 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;
	size_t	lensum;

	i = 0;
	j = 0;
	if (s1 == 0)
		s1 = get_strdup("");
	lensum = get_strlen(s1) + get_strlen(s2);
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

char	*get_strdup(char *s)
{
	char	*tmp;
	size_t	len;
	int		i;

	i = 0;
	len = get_strlen(s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*temp;

	if (s == 0)
		return (0);
	if (start >= get_strlen(s))
		return (get_strdup(""));
	i = 0;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == 0)
		return (0);
	temp[len] = 0;
	while (i < len)
	{
		temp[i] = s[start + i];
		i++;
	}
	return (temp);
}

char	*eqal_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*temp;

	if (s == 0)
		return (0);
	if (start >= get_strlen(s))
	{
		free(s);
		return (0);
	}
	i = 0;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == 0)
		return (0);
	temp[len] = 0;
	while (i < len)
	{
		temp[i] = s[start + i];
		i++;
	}
	free(s);
	return (temp);
}
