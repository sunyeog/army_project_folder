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

void	error(int num)
{
	if (num == 1)
	{
		ft_printf("Error\nit's not rectangular.\n");
		exit(1);
	}
	else if (num == 2)
	{
		ft_printf("Error\nfile_open_error\n");
		exit(1);
	}
	else if (num == 3)
	{
		ft_printf("Error\nmalloc_error\n");
		exit(1);
	}
	else if (num == 4)
	{
		ft_printf("Error\nmap_error\n");
		exit(1);
	}
}

int	open_file(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error(2);
	return (fd);
}

void	mk_map_arr(int fd, t_game *game)
{
	char	*tmp_arr;
	char	*res_arr;

	tmp_arr = get_next_line(fd);
	res_arr = malloc(sizeof(char) * 1);
	if (res_arr == 0)
		error(3);
	res_arr[0] = '\0';

	while (tmp_arr != NULL)
	{
		res_arr = ft_strjoin(res_arr, tmp_arr);
		free(tmp_arr);
		if (res_arr == NULL)
		error(3);
		tmp_arr = get_next_line(fd);
	}
	game -> map = ft_split(res_arr, '\n');
	if (game -> map == NULL || game -> map[0] == NULL)
	{
		ft_printf("error\nblank_or_segfault_error\n");
		exit(1);
	}
	free(res_arr);
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
