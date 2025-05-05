#include "../includes/so_long.h"

void	init_enemies(t_game *game)
{
	int x;
    int y;
    int i;
    int count;

    count = character_count(game, 'M');
    if (count == 0)
    {
        game->enemies = NULL;
        game->enemy_count = 0;
		return ;
    }
    game->enemies = malloc(sizeof(t_enemy *) * count);
    if (!game->enemies)
    {
        free_all(game);
        exit (1);
    }
    i = 0;
    y = 0;
	while (y < game->map->height)
	{
        x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'M')
			{
				game->enemies[i] = malloc(sizeof(t_enemy));
				if (!game->enemies[i])
                {
                    free_all(game);
					exit(1);
                }
                game->enemies[i]->x = x;
                game->enemies[i]->y = y;
                game->enemies[i]->dir = get_next_direction();
                i++;
			}
            x++;
		}
        y++;
	}
	game->enemy_count = count;
}

void	load_enemy_images(t_game *game, t_enemy *enemy)
{
    if (!game->enemies)
	    return ;
	if (game->img->img_enemy)
		mlx_destroy_image(game->mlx, game->img->img_enemy);
	if (enemy->dir == DIR_LEFT)
		game->img->img_enemy = file_to_img(game, "textures/enemy_l.xpm");
	else if (enemy->dir == DIR_RIGHT)
		game->img->img_enemy = file_to_img(game, "textures/enemy_r.xpm");
    else if (enemy->dir == DIR_UP)
		game->img->img_enemy = file_to_img(game, "textures/enemy_up.xpm");
	else
		game->img->img_enemy = file_to_img(game, "textures/enemy.xpm");
}