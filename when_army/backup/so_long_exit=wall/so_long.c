/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:38:58 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/07/10 13:53:46 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game -> cnt_e = 0;
	game -> cnt_c = 0;
	game -> cnt_p = 0;
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
