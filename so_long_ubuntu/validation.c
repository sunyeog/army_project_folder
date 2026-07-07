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
		error(4);
}

char **cp_map(char **map, int size)
{
	int	i;
	char	**dup_map;

	i = 0;
	dup_map = (char**)malloc(sizeof(char *) * (size + 1));
	if (dup_map == NULL)
		error(3);
	ft_bzero(dup_map, sizeof(char *) * (size + 1));
	while (i < size)
	{
		dup_map[i] = ft_strdup(map[i]);
		if (dup_map[i] == NULL)
		{
			split_free(dup_map);
			error(3);
		}	
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}

int	dfs(char **map, t_game *game, int row, int col)
{
	if (map[row][col] == '1')
		return (0);
	dfs(map, game, row - 1, col);
	dfs(map, game, row + 1, col);
	dfs(map, game, row, col - 1);
	dfs(map, game, row, col + 1);
}