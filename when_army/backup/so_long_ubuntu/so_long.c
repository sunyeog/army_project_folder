/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:38:58 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/10 05:58:34 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_game *game)
{
	mlx_destroy_image(game -> mlx, game -> road);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->c);
	mlx_destroy_image(game->mlx, game->e);
	mlx_destroy_image(game->mlx, game->p);
	mlx_destroy_window(game->mlx, game->wd);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	split_free(game->map);
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

void	find_start_point(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game -> map[i] != NULL)
	{
		j = 0;
		while (game -> map[i][j] != '\0')
		{
			if (game -> map[i][j] == 'P')
			{
				game -> row = i;
				game -> col = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_wh(t_game *game)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (game -> map[0][j] != '\0')
		j++;
	game -> w = j;
	while (game -> map[i] != NULL)
		i++;
	game -> h = i;
}

void	split_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**dup_map;
	t_game	game;

	check_av(ac, av);
	fd = open_file(av);
	mk_map_arr(fd, &game);
	find_start_point(&game);
	find_wh(&game);
	start_map_check(&game);
	rect_check(&game);
	dup_map = cp_map(game.map, game.h);
	dfs_check(dup_map, game.row, game.col, &game);
	split_free(dup_map);
	game.print_cnt = 0;
	game.mlx = mlx_init();
	game.wd = mlx_new_window(game.mlx, 64 * game.w, 64 * game.h, "start");
	load_image(&game);
	print_map(&game);
	mlx_key_hook(game.wd, &key_control, &game);
	mlx_hook(game.wd, 17, 0, &end_game, &game);
	mlx_loop(game.mlx);
	close(fd);
	return (0);
}
