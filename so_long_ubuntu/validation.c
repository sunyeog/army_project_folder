#include "so_long.h"

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
	if (game -> cnt_e != 1 || game -> cnt_p != 1 || game -> cnt_c == 0)
	{
		ft_printf("error\nmap_error\n");
		exit(1);
	}
}

int	dfs(char **p, t_game *game, int case)
{
	if (case == 1 && p[game -> row][game -> col] == '1')
	{
		game -> row++;
		return(0);
	}
	if (case == 2 && p[game -> row][game -> col] == '1')
	{
		game -> row--;
		return(0);
	}
	if (case == 3 && p[game -> row][game -> col] == '1')
	{
		game -> col++;
		return(0);
	}
	if (case == 4 && p[game -> row][game -> col] == '1')
	{
		game -> col--;
		return(0);
	}
	if (p == 'E')
		return (1);
	if (dfs(p[game -> row - 1][game -> col]) == 1)
		return (1);
	if (dfs(p[game -> row + 1][game -> col]) == 1)
		return (1);
	if (dfs(p[game -> row][game -> col - 1]) == 1)
		return (1);
	if (dfs(p[game -> row][game -> col + 1]) == 1)
		return (1);
}