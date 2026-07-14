/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 00:58:55 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/10 14:02:34 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_empty_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	start_map_check(t_game *game)
{
	int	i;
	int	j;

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
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				error(4, game);
			j++;
		}
		i++;
	}
	if (game -> cnt_e != 1 || game -> cnt_p != 1 || game -> cnt_c == 0)
		error(4, game);
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
			error(1, game);
		i++;
	}
	s_len = i;
	i = 0;
	while (i < len)
	{
		if (game -> map[0][i] != '1' || game -> map[s_len - 1][i] != '1')
			error(1, game);
		i++;
	}
}
