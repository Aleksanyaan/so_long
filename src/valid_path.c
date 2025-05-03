#include "../includes/so_long.h"

char	**copy_map(char **map, int height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (!map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	flood_fill(t_fill *fill, int x, int y)
{
	if (x < 0 || y < 0 || x >= fill->height || y >= fill->width)
		return ;
	if (fill->map[x][y] == '1' || fill->map[x][y] == 'V' || fill->map[x][y] == 'M')
		return ;
	if (fill->map[x][y] == 'C')
		fill->collectibles_found++;
	else if (fill->map[x][y] == 'E')
	{
		fill->exits_found++;
		return ;
	}
	fill->map[x][y] = 'V';

	flood_fill(fill, x + 1, y);
	flood_fill(fill, x - 1, y);
	flood_fill(fill, x, y + 1);
	flood_fill(fill, x, y - 1);
}

int	valid_path(t_game *game)
{
	char	**map_copy;
	t_fill	fill;

	map_copy = copy_map(game->map->map, game->map->height);
	if (!map_copy)
		return (0);
	fill.map = map_copy;
	fill.width = game->map->width;
	fill.height = game->map->height;
	fill.collectibles_found = 0;
	fill.exits_found = 0;
    if (game->player->x < 0 || game->player->y < 0
            || game->player->x >= game->map->width
            || game->player->y >= game->map->height)
    {
        free_map(map_copy);
        return (0);
    }    
	flood_fill(&fill, game->player->y, game->player->x);
	free_map(map_copy);
	if (fill.collectibles_found != game->collectibles
		|| fill.exits_found == 0)
		return (0);
	return (1);
}
