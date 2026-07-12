/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:01:17 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/10 14:01:49 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cp_map(char **map, int size)
{
	int		i;
	char	**dup_map;

	i = 0;
	dup_map = (char **)malloc(sizeof(char *) * (size + 1));
	if (dup_map == NULL)
		error(3, NULL);
	ft_bzero(dup_map, sizeof(char *) * (size + 1));
	while (i < size)
	{
		dup_map[i] = ft_strdup(map[i]);
		if (dup_map[i] == NULL)
		{
			split_free(dup_map);
			error(3, NULL);
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
	if (map[row][col] == 'E')
	{
		map[row][col] = '1';
		return ;
	}
	map[row][col] = '1';
	dfs(map, row - 1, col);
	dfs(map, row + 1, col);
	dfs(map, row, col - 1);
	dfs(map, row, col + 1);
}

void	dfs_check(char **map, int row, int col, t_game *game)
{
	dfs(map, row, col);
	if (cnt_char(map, 'C') != 0 || cnt_char(map, 'E') != 0)
	{
		split_free(map);
		split_free(game -> map);
		error(4, NULL);
	}
}
