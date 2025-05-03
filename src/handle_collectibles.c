#include "../includes/so_long.h"

int	character_count(t_game *game, char c)
{
	int	i;
	int	j;
	int	count;

	if (!game || !game->map || !game->map->map)
		return (0);
	i = 0;
	count = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_blocked(char tile, int collectibles)
{
	if (tile == '1')
		return (1);
	if (tile == 'E' && collectibles > 0)
		return (1);
	return (0);
}

void	handle_collectible(t_game *game, int x, int y)
{
	game->collectibles--;
	game->map->map[y][x] = '0';
}
