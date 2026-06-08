/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:50:10 by sunhnoh           #+#    #+#             */
/*   Updated: 2026/04/10 03:08:34 by codespace        ###   ########.fr       */
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
	
}	t_str;

typedef struct f_game
{
	char	**map;
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

#endif
