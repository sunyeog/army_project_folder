/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:41:22 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/08/22 15:08:23 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*bu = 0;
	ssize_t		r_len;
	char		*temp;
	char		*res;

	while (1)
	{
		temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (temp == 0)
			return (0);
		r_len = read(fd, temp, BUFFER_SIZE);
		if (r_len < 0)
			return (free_and_reset(&bu, &temp));
		temp[r_len] = 0;
		bu = get_strjoin(bu, temp);
		free(temp);
		temp = 0;
		if (f_ent(bu) > 0)
			return (return_res(0, &res, &bu));
		else if (*bu == '\0' || r_len == -1)
			return (free_and_reset(&bu, &temp));
		else if (!(f_ent(bu)) && r_len == 0)
			return (return_res(1, &res, &bu));
	}
}

char	*return_res(int i, char **res, char **bu)
{
	if (i == 0)
	{
		*res = get_substr(*bu, 0, f_ent(*bu));
		*bu = eqal_substr(*bu, f_ent(*bu), get_strlen(*bu) - f_ent(*bu));
		return (*res);
	}
	else
	{
		*res = get_strdup(*bu);
		free(*bu);
		*bu = 0;
		return (*res);
	}
}

char	*free_and_reset(char **bu, char **temp)
{
	free(*bu);
	if (*temp)
	{
		free(*temp);
		*temp = 0;
	}
	*bu = 0;
	return (0);
}

int	f_ent(char *a)
{
	int	i;

	i = 0;
	while (*a)
	{
		if (*a == '\n')
			return (i + 1);
		a++;
		i++;
	}
	return (0);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd = open("test.txt",O_RDONLY);

	printf("%s", get_next_line(fd));
}*/
