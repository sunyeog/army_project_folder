/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <sunhnoh@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:38:58 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/12/06 13:24:57 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


void	print_map(char **t, void *temp, void *win)
{
	int	i = 0;
	int j = 0;
	int r;
	int	c;
	f_str s1;

	while (t[i])
	{
		j = 0;
		while (t[i][j])
		{
			if(t[i][j] == '0')
			{
				s1.zero = mlx_xpm_file_to_image(temp, "./empty_space.xpm",&r, &c);
				mlx_put_image_to_window(temp, win, s1.zero, j * 64, i * 64);
			}
			else if(t[i][j] == '1')
			{
				s1.one = mlx_xpm_file_to_image(temp, "./wall.xpm",&r, &c);
				mlx_put_image_to_window(temp, win, s1.one, j * 64, i * 64);
			}
			else if(t[i][j] == 'C')
			{
				s1.c = mlx_xpm_file_to_image(temp, "./collectible.xpm",&r, &c);
				mlx_put_image_to_window(temp, win, s1.c, j * 64, i * 64);
			}
			else if(t[i][j] == 'E')
			{
				s1.e = mlx_xpm_file_to_image(temp, "./exit.xpm",&r, &c);
				mlx_put_image_to_window(temp, win, s1.e, j * 64, i * 64);
			}
			else if(t[i][j] == 'P')
			{
				s1.p = mlx_xpm_file_to_image(temp, "./frisk.xpm",&r, &c);
				mlx_put_image_to_window(temp, win, s1.p, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

int	check_wall(f_game *game, int num)
{
	if (num == 126)
	{
		if (game -> map[game -> row - 1][game -> col] == '1')
			return (-1);
	}
	else if (num == 125)
	{
		if (game -> map[game -> row + 1][game -> col] == '1')
			return (-1);
	}
	else if (num == 123)
	{
		if (game -> map[game -> row][game -> col - 1] == '1')
			return (-1);
	}
	else if (num == 124)
	{
		if (game -> map[game -> row][game -> col + 1] == '1')
			return (-1);
	}
	return (1);
}
////////////////////////////////////
int	map_check(f_game *game)
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
	ft_printf("c: %d\ne:%d\n", game -> cnt_c, game -> cnt_e);
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
//////////////////////////////////////////
int	check_exit(f_game *game, int num)
{
	if (num == 126 && game -> map[game -> row - 1][game -> col] == 'E' 
			&& map_check(game) == 1)
			return (-1);
	else if (num == 125 && game -> map[game -> row + 1][game -> col] == 'E' 
			&& map_check(game) == 1)
			return (-1);
	else if (num == 123 && game -> map[game -> row][game -> col - 1] == 'E' 
			&& map_check(game) == 1)
			return (-1);
	else if (num == 124 && game -> map[game -> row][game -> col + 1] == 'E' 
			&& map_check(game) == 1)
			return (-1);
	return (1);
}
///////////////////////////////////////////
int	key_control(int keycode, f_game *game)
{
	if (keycode == 53)
		exit(0);
	if (check_wall(game, keycode) == -1)
		return (0);
	if (check_exit(game, keycode) == -1)
		return (0);
	ft_printf("%d\n", check_exit(game, keycode));
	game -> map[game -> row][game -> col] = '0';
	if (keycode == 126)
		game -> row -= 1; 
	else if (keycode == 125)
		game -> row += 1; 
	else if (keycode == 123)
		game -> col -= 1; 
	else if (keycode == 124)
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
void	find_start_point(f_game *game)
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
				return;
			}
			j++;
		}
		i++;
	}
	//return (0);
}


/*void	find_start_col(f_game *game)
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
				game -> col = j;
				//return (j);
			j++;
		}
		i++;
	}
	//return(0);
}*/

int	find_width(f_game *game)
{
	int	j;

	j = 0;
	while (game -> map[0][j] != '\0')
		j++;
	return (j);
}

int	find_height(f_game *game)
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
/////////////////////////////////////////////////////////////////
void	rect_check(f_game *game)
{
	int	len;
	int	s_len;
	int	i;

	len = ft_strlen(game -> map[0]);
	i = 0;
	while (game -> map[i])
	{
		s_len = ft_strlen(game -> map[i]);
		if (s_len != len ||
				game -> map[i][0] != '1' || game -> map[i][len - 1] != '1')
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

void	start_map_check(f_game *game)
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
	if (game -> cnt_e != 1 || game -> cnt_p != 1 || game -> cnt_c == 0
			|| game -> w < 3 || game -> h < 3)
	{
		ft_printf("map error\n");
		exit(0);
	}
}



int main(int ac, char **av)
{
	int	fd;
	char *ttt;
	char *tt;
	f_game game;

	if (ac != 2)
	{
		ft_printf("error\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("this file there isn't this directory\n");
		return (0);
	}
	ttt = get_next_line(fd);
	tt = malloc(sizeof(char) * 1);
	tt[0] = '\0';
	while (ttt != NULL)
	{
		tt = ft_strjoin(tt, ttt);
		ttt = get_next_line(fd);
	}
	game.map = ft_split(tt, '\n');
	find_start_point(&game);
	game.w = find_width(&game);
	game.h = find_height(&game);
	start_map_check(&game);
	rect_check(&game);
	game.print_cnt = 0;
	
	game.temp = mlx_init();
	game.win = mlx_new_window(game.temp, 64 * game.w, 64 * game.h, "start");

	print_map(game.map, game.temp, game.win);
	mlx_key_hook(game.win, &key_control, &game);
	//mlx_key_hook(game.win, &key_control, &game);
	mlx_hook(game.win, 17, 0, &exit_func, NULL);
	mlx_loop(game.temp);
	return (0);
}
