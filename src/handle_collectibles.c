#include "../includes/so_long.h"

int	collectible_count(t_game *game)
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
			if (game->map->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	is_blocked(char tile, int collectibles)
{
	if (tile == '1')
		return (1);
	if (tile == 'E' && collectibles > 0)
		return (1);
	return (0);
}

static void	handle_collectible(t_game *game, int x, int y)
{
	game->collectibles--;
	game->map->map[y][x] = '0';
}

void	move_to(t_game *game, int x_offset, int y_offset)
{
	int		x;
	int		y;
	int		new_x;
	int		new_y;
	char	next_tile;

	x = game->player->x;
	y = game->player->y;
	new_x = x + x_offset;
	new_y = y + y_offset;
	game->collectibles = collectible_count(game);
	next_tile = game->map->map[new_y][new_x];
	if (is_blocked(next_tile, game->collectibles))
		return ;
	if (next_tile == 'E')
		close_window(game);
	if (next_tile == 'C')
		handle_collectible(game, new_x, new_y);
	game->player->x = new_x;
	game->player->y = new_y;
	game->moves++;
	draw_tile(game, game->img->img_player, new_x, new_y);
	draw_tile(game, game->img->img_floor, x, y);
	// show_moves(game);
}
