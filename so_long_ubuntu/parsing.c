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

int	check_av(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("error\n");
		return (0);
	}

}
