#include "../includes/so_long.h"

int	get_next_direction()
{
	static int	counter = 0;

	counter++;
	return (counter % 4);
}


void	move_enemy(t_game *game, t_enemy *enemy)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
	int new_x;
	int new_y;
    char next_tile;

    if (!game->enemies)
        return ;

    new_x = enemy->x + dx[enemy->dir];
    new_y = enemy->y + dy[enemy->dir];
	if (new_x < 0 || new_x >= game->map->width
        || new_y < 0 || new_y >= game->map->height)
	{
		enemy->dir = get_next_direction();
		return ;
	}
    if (new_x == game->player->x && new_y == game->player->y)
	{
		write(1, "Caught by enemy!\n", 17);
		cleanup(game);
        free_map(game->map->map);
        free_all(game);
		exit(0);
	}
	next_tile = game->map->map[new_y][new_x];
    if (next_tile == '0')
	{
		game->map->map[enemy->y][enemy->x] = '0';
		game->map->map[new_y][new_x] = 'M';
		enemy->x = new_x;
        enemy->y = new_y;
	}
	else
        enemy->dir =  get_next_direction();
    load_enemy_images(game, enemy); 
}
