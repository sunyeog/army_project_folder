/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:38:58 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/12/17 10:29:04 by sunhnoh          ###   ########.fr       */
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
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	split_free(game->map);
	return (0);
}

void	load_image(t_game *game)
{
	int	wi;
	int	he;

	game -> road = mlx_xpm_file_to_image(game -> mlx, "./empty_space.xpm", &wi, &he);
	game -> wall = mlx_xpm_file_to_image(game -> mlx, "./wall.xpm", &wi, &he);
	game -> c = mlx_xpm_file_to_image(game -> mlx, "./collectible.xpm", &wi, &he);
	game -> e = mlx_xpm_file_to_image(game -> mlx, "./exit.xpm", &wi, &he);
	game -> p = mlx_xpm_file_to_image(game -> mlx, "./frisk.xpm", &wi, &he);
}

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game -> map[i])
	{
		j = 0;
		while (game -> map[i][j])
		{
			if (game -> map[i][j] == '0')
				mlx_put_image_to_window(game -> mlx, game -> win, game -> road, j * 64, i * 64);
			else if (game -> map[i][j] == '1')
				mlx_put_image_to_window(game -> mlx, game -> win, game -> wall, j * 64, i * 64);
			else if (game -> map[i][j] == 'C')
				mlx_put_image_to_window(game -> mlx, game -> win, game -> c, j * 64, i * 64);
			else if (game -> map[i][j] == 'E')
				mlx_put_image_to_window(game -> mlx, game -> win, game -> e, j * 64, i * 64);
			else if (game -> map[i][j] == 'P')
				mlx_put_image_to_window(game -> mlx, game -> win, game -> p, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	check_wall(t_game *game, int num)
{
	if (num == 65362 || num == 119)
	{
		if (game -> map[game -> row - 1][game -> col] == '1')
			return (-1);
	}
	else if (num == 65364 || num == 115)
	{
		if (game -> map[game -> row + 1][game -> col] == '1')
			return (-1);
	}
	else if (num == 65361 || num == 97)
	{
		if (game -> map[game -> row][game -> col - 1] == '1')
			return (-1);
	}
	else if (num == 65363 || num == 100)
	{
		if (game -> map[game -> row][game -> col + 1] == '1')
			return (-1);
	}
	return (1);
}

int	map_check(t_game *game)
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
				game -> cnt_e--;
			else if (game -> map[i][j] == 'C')
				game -> cnt_c--;
			j++;
		}
		i++;
	}
	if (game->cnt_c == 0)
	{
		end_game(game);
		exit(0);
	}
	if (game->cnt_c != 0)
		return (1);
	return (0);
}

int	check_exit(t_game *game, int num)
{
	if ((num == 65362 || num == 119) && game -> map[game -> row - 1][game -> col] == 'E'
			&& map_check(game) == 1)
		return (-1);
	else if ((num == 65364 || num == 115) && game -> map[game -> row + 1][game -> col] == 'E'
			&& map_check(game) == 1)
		return (-1);
	else if ((num == 65361 || num == 97) && game -> map[game -> row][game -> col - 1] == 'E'
			&& map_check(game) == 1)
		return (-1);
	else if ((num == 65363 || num == 100) && game -> map[game -> row][game -> col + 1] == 'E'
			&& map_check(game) == 1)
		return (-1);
	return (1);
}

int	key_control(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		end_game(game);
		exit(0);
	}
	if (check_wall(game, keycode) == -1)
		return (0);
	if (check_exit(game, keycode) == -1)
		return (0);
	game -> map[game -> row][game -> col] = '0';
	if (keycode == 65362 || keycode == 119)
		game -> row--;
	else if (keycode == 65364 || keycode == 115)
		game -> row++;
	else if (keycode == 65361 || keycode == 97)
		game -> col--;
	else if (keycode == 65363 || keycode == 100)
		game -> col++;
	game -> map[game -> row][game -> col] = 'P';
	print_map(game);
	game -> print_cnt += 1;
	ft_printf("%d\n", game -> print_cnt);
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

void	find_width(t_game *game)
{
	int	j;

	j = 0;
	while (game -> map[0][j] != '\0')
		j++;
	game -> w = j;
}

void	find_height(t_game *game)
{
	int	i;

	i = 0;
	while (game -> map[i] != NULL)
		i++;
	game -> h = i;
}

void    split_free(char **arr)
{
        int     i;

        i = 0;
        while (arr[i])
        {
                free(arr[i]);
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
	find_width(&game);
	find_height(&game);
	start_map_check(&game);
	rect_check(&game);
	dup_map = cp_map(game.map, game.h);
	dfs(dup_map, game.row, game.col);
	if (cnt_char(dup_map, 'C') != 0 || cnt_char(dup_map, 'E') != 0)
	{
		split_free(dup_map);
		split_free(game.map);
		error(4);
	}
	split_free(dup_map);

	game.print_cnt = 0;
	game.mlx = mlx_init(); // mlx초기화, 일종의 mlx시작버튼
	game.win = mlx_new_window(game.mlx, 64 * game.w, 64 * game.h, "start");
	// 윈도우 생성후 윈도우 포인터 반환(mlx인스턴스, 너비, 높이, 창 제목)
	load_image(&game);
	print_map(&game);
	mlx_key_hook(game.win, &key_control, &game);
	// 키보드 입력 이벤트 등록.(윈도우, 키 눌렸을 때 호출할 함수, 그 함수의 매개변수) 
	mlx_hook(game.win, 17, 0, &end_game, &game);
	// 특정 위도우 이벤트에 함수등록.(이벤트 받을 윈도우,이벤트 번호,마스크?, 호출될 함수, 넘겨줄 파라미터)
	mlx_loop(game.mlx);
	// 키 입력, 이벤트 등을 기다림
	close(fd);
	return (0);
}