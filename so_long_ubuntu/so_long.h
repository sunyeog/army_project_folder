/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:50:10 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/12/06 14:32:57 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./Libft/libft.h"
# include "get_next_line.h"
# include "./Libft/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct f_struct
{
	void	*zero;
	void	*one;
	void	*c;
	void	*e;
	void	*p;
}	t_str;

typedef struct f_game
{
	char	**map;
	char	**test_map;
	int		row;
	int		col;
	int		w;
	int		h;
	void	*temp;
	void	*win;
	int		print_cnt;
	int		cnt_e;
	int		cnt_c;
	int		cnt_p;
}	t_game;

int	open_file(char **av);
void	mk_map_arr(int fd, t_game *game);
int	check_extension(char *av);
void	check_av(int ac, char **av);

void	start_map_check(t_game *game);

#endif