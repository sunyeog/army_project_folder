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

void	print_map(char **t, void *temp, void *win)
{
	int	i;
	int	j;
	int	r;
	int	c;
	t_str	s1;

	i = 0;
	while (t[i])
	{
		j = 0;
		while (t[i][j])
		{
			if (t[i][j] == '0')
			{
				s1.zero = mlx_xpm_file_to_image(temp, "./empty_space.xpm", &r, &c);
				mlx_put_image_to_window(temp, win, s1.zero, j * 64, i * 64);
			}
			else if (t[i][j] == '1')
			{
				s1.one = mlx_xpm_file_to_image(temp, "./wall.xpm", &r, &c);
				mlx_put_image_to_window(temp, win, s1.one, j * 64, i * 64);
			}
			else if (t[i][j] == 'C')
			{
				s1.c = mlx_xpm_file_to_image(temp, "./collectible.xpm", &r, &c);
				mlx_put_image_to_window(temp, win, s1.c, j * 64, i * 64);
			}
			else if (t[i][j] == 'E')
			{
				s1.e = mlx_xpm_file_to_image(temp, "./exit.xpm", &r, &c);
				mlx_put_image_to_window(temp, win, s1.e, j * 64, i * 64);
			}
			else if (t[i][j] == 'P')
			{
				s1.p = mlx_xpm_file_to_image(temp, "./frisk.xpm", &r, &c);
				mlx_put_image_to_window(temp, win, s1.p, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

int	check_wall(t_game *game, int num)
{
	if (num == 65362)
	{
		if (game -> map[game -> row - 1][game -> col] == '1')
			return (-1);
	}
	else if (num == 65364)
	{
		if (game -> map[game -> row + 1][game -> col] == '1')
			return (-1);
	}
	else if (num == 65361)
	{
		if (game -> map[game -> row][game -> col - 1] == '1')
			return (-1);
	}
	else if (num == 65363)
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
			j++;
		}
		i++;
	}
	if (game->cnt_c == 0 && game->cnt_e == 1)
	{
		ft_printf("ok\n");
		exit (0);
	}
	if (game->cnt_c != 0)
	{
		ft_printf("not\n");
		return (1);
	}
	return (0);
}

int	check_exit(t_game *game, int num)
{
	if (num == 65362 && game -> map[game -> row - 1][game -> col] == 'E'
			&& map_check(game) == 1)
		return (-1);
	else if (num == 65364 && game -> map[game -> row + 1][game -> col] == 'E'
			&& map_check(game) == 1)
		return (-1);
	else if (num == 65361 && game -> map[game -> row][game -> col - 1] == 'E'
			&& map_check(game) == 1)
		return (-1);
	else if (num == 65363 && game -> map[game -> row][game -> col + 1] == 'E'
			&& map_check(game) == 1)
		return (-1);
	return (1);
}

int	key_control(int keycode, t_game *game)
{
	ft_printf("key : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (check_wall(game, keycode) == -1)
		return (0);
	if (check_exit(game, keycode) == -1)
		return (0);
	game -> map[game -> row][game -> col] = '0';
	if (keycode == 65362)
		game -> row -= 1;
	else if (keycode == 65364)
		game -> row += 1;
	else if (keycode == 65361)
		game -> col -= 1;
	else if (keycode == 65363)
		game -> col += 1;
	game -> map[game -> row][game -> col] = 'P';
	print_map(game -> map, game -> temp, game -> win);
	game -> print_cnt += 1;
	ft_printf("%d\n", game -> print_cnt);
	return (0);
}

int	exit_func(void *param)
{
	(void)param;
	exit(0);
}

//void	find_start_col(f_game *game)
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

int	find_width(t_game *game)
{
	int	j;

	j = 0;
	while (game -> map[0][j] != '\0')
		j++;
	return (j);
}

int	find_height(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game -> map[i] != NULL)
	{
		j = 0;
		while (game -> map[i][j] != '\0')
			j++;
		i++;
	}
	return (i);
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
		{
			ft_printf("it's not rectangular.\n");
			exit(1);
		}
		i++;
	}
	s_len = i;
	i = 0;
	while (i < len)
	{
		if (game -> map[0][i] != '1' || game -> map[s_len - 1][i] != '1')
		{
			ft_printf("it's not rectangular.\n");
			exit(1);
		}
		i++;
	}
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
	t_game	game;
	
	check_av(ac, av);
	fd = open_file(av);
	mk_map_arr(fd, &game);

	find_start_point(&game);
	game.w = find_width(&game);
	game.h = find_height(&game);
	start_map_check(&game);
	rect_check(&game);
	game.print_cnt = 0;
	game.temp = mlx_init(); // mlx초기화, 일종의 mlx시작버튼
	game.win = mlx_new_window(game.temp, 64 * game.w, 64 * game.h, "start");
	// 윈도우 생성후 윈도우 포인터 반환(mlx인스턴스, 너비, 높이, 창 제목)
	print_map(game.map, game.temp, game.win);
	mlx_key_hook(game.win, &key_control, &game);
	// 키보드 입력 이벤트 등록.(윈도우, 키 눌렸을 때 호출할 함수, 그 함수의 매개변수) 
	mlx_hook(game.win, 17, 0, &exit_func, NULL);
	// 특정 위도우 이벤트에 함수등록.(이벤트 받을 윈도우,이벤트 번호,마스크?, 호출될 함수, 넘겨줄 파라미터)
	mlx_loop(game.temp);
	// 키 입력, 이벤트 등을 기다림
	close(fd);
	return (0);
}