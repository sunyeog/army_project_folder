/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:23:27 by codespace         #+#    #+#             */
/*   Updated: 2026/06/21 14:41:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nfile_open_error\n");
		exit(1);
	}
	return (fd);
}

void	mk_map_arr(int fd, t_game *game)
{
	char	*tmp_arr;
	char	*res_arr;

	tmp_arr = get_next_line(fd);
	res_arr = malloc(sizeof(char) * 1);
	res_arr[0] = '\0';

	while (tmp_arr != NULL)
	{
		res_arr = ft_strjoin(res_arr, tmp_arr);
		free(tmp_arr);
		tmp_arr = get_next_line(fd);
	}
	game -> map = ft_split(res_arr, '\n');
	free(res_arr);
}

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
	if (game -> cnt_e != 1 || game -> cnt_p != 1 || game -> cnt_c == 0
		|| game -> w < 3 || game -> h < 3)
	{
		ft_printf("map error\n");
		exit(0);
	}
}

int	check_extension(char *av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i] == '.')
		{
			j = i + 1;
			if (av[j++] == 'b' && av[j++] == 'e' && av[j++] == 'r' && av[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

void	check_av(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("error\nac isn't 2\n");
		exit(1);
	}
	if (check_extension(av[1]) == 0)
	{
		ft_printf("error\nextension_error\n");
		exit(1);
	}
}
