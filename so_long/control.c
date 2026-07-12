/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:59:54 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/10 14:00:23 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	save_value(int keycode, t_game *game)
{
	char	c;

	c = 0;
	if (keycode == 65362 || keycode == 119)
		c = game -> map[game -> row - 1][game -> col];
	else if (keycode == 65364 || keycode == 115)
		c = game -> map[game -> row + 1][game -> col];
	else if (keycode == 65361 || keycode == 97)
		c = game -> map[game -> row][game -> col - 1];
	else if (keycode == 65363 || keycode == 100)
		c = game -> map[game -> row][game -> col + 1];
	return (c);
}

void	act(int keycode, t_game *game)
{
	char	c;

	c = save_value(keycode, game);
	if (c == 'E' && game -> cnt_c == 0)
		end_game(game);
	else if (c == 'E' || c == '1')
		return ;
	else
	{
		if (c == 'C')
			game -> cnt_c--;
		if (keycode == 65362 || keycode == 119)
			game -> row--;
		else if (keycode == 65364 || keycode == 115)
			game -> row++;
		else if (keycode == 65361 || keycode == 97)
			game -> col--;
		else if (keycode == 65363 || keycode == 100)
			game -> col++;
		game -> print_cnt += 1;
		ft_printf("%d\n", game -> print_cnt);
	}
}

int	key_control(int keycode, t_game *game)
{
	if (keycode == 65307)
		end_game(game);
	game -> map[game -> row][game -> col] = '0';
	act(keycode, game);
	game -> map[game -> row][game -> col] = 'P';
	print_map(game);
	return (0);
}
