/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:57:16 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/10 13:58:55 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_game *game)
{
	mlx_destroy_image(game -> mlx, game -> road);
	mlx_destroy_image(game -> mlx, game -> wall);
	mlx_destroy_image(game -> mlx, game -> c);
	mlx_destroy_image(game -> mlx, game -> e);
	mlx_destroy_image(game -> mlx, game -> p);
	mlx_destroy_window(game -> mlx, game -> wd);
	mlx_destroy_display(game -> mlx);
	free(game -> mlx);
	split_free(game -> map);
	exit(0);
}

void	load_image(t_game *game)
{
	int	wi;
	int	he;

	game -> road = mlx_xpm_file_to_image(game -> mlx, "./r.xpm", &wi, &he);
	game -> wall = mlx_xpm_file_to_image(game -> mlx, "./w.xpm", &wi, &he);
	game -> c = mlx_xpm_file_to_image(game -> mlx, "./c.xpm", &wi, &he);
	game -> e = mlx_xpm_file_to_image(game -> mlx, "./e.xpm", &wi, &he);
	game -> p = mlx_xpm_file_to_image(game -> mlx, "./p.xpm", &wi, &he);
}

void	*pick(t_game *game, char c)
{
	if (c == '1')
		return (game -> wall);
	if (c == 'C')
		return (game -> c);
	if (c == 'E')
		return (game -> e);
	if (c == 'P')
		return (game -> p);
	return (game -> road);
}

void	print_map(t_game *game)
{
	int		i;
	int		j;
	void	*p;

	i = 0;
	while (game -> map[i])
	{
		j = 0;
		while (game -> map[i][j])
		{
			p = pick(game, game -> map[i][j]);
			mlx_put_image_to_window(game -> mlx, game -> wd, p, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
