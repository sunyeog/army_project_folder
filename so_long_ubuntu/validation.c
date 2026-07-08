/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 00:58:55 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/08 00:59:01 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_map_check(t_game *game)
{
	int	i;
	int	j;

	game -> cnt_e = 0;
	game -> cnt_c = 0;
	game -> cnt_p = 0;
	i = 0;
	while (game -> map[i] != NULL)
	{
		j = 0;
		while (game -> map[i][j] != '\0')
		{
			if (game -> map[i][j] == 'E')
				game -> cnt_e++;
			else if (game -> map[i][j] == 'C')
				game -> cnt_c++;
			else if (game -> map[i][j] == 'P')
				game -> cnt_p++;
			j++;
		}
		i++;
	}
	if (game -> cnt_e != 1 || game -> cnt_p != 1 || game -> cnt_c == 0)
		error(4);
}

void	rect_check(t_game *game)
{
	int	len;
	int	s_len;
	int	i;

	len = ft_strlen(game -> map[0]);
	i = 0;
	while (game -> map[i])
	{
		s_len = ft_strlen(game -> map[i]);
		if (s_len != len || game -> map[i][0] != '1' ||
				game -> map[i][len - 1] != '1')
			error(1);
		i++;
	}
	s_len = i;
	i = 0;
	while (i < len)
	{
		if (game -> map[0][i] != '1' || game -> map[s_len - 1][i] != '1')
			error(1);
		i++;
	}
}

char **cp_map(char **map, int size)
{
	int	i;
	char	**dup_map;

	i = 0;
	dup_map = (char**)malloc(sizeof(char *) * (size + 1));
	if (dup_map == NULL)
		error(3);
	ft_bzero(dup_map, sizeof(char *) * (size + 1));
	while (i < size) 
	{
		dup_map[i] = ft_strdup(map[i]);
		if (dup_map[i] == NULL)
		{
			split_free(dup_map);
			error(3);
		}	
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}

int	cnt_char(char **map, char c)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

void	dfs(char **map, int row, int col)
{
	if (map[row][col] == '1')
		return ;
	map[row][col] = '1';
	dfs(map, row - 1, col);
	dfs(map, row + 1, col);
	dfs(map, row, col - 1);
	dfs(map, row, col + 1);
}