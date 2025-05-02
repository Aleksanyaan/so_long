#include "../includes/so_long.h"

void	load_player_images(t_game *game)
{
	if (game->img->img_player)
		mlx_destroy_image(game->mlx, game->img->img_player);
	if (game->player->dir == 'L')
		game->img->img_player = file_to_img(game, "textures/player_l.xpm");
	else if (game->player->dir == 'R')
		game->img->img_player = file_to_img(game, "textures/player_r.xpm");
	else if (game->player->dir == 'U')
		game->img->img_player = file_to_img(game, "textures/player_b.xpm");
	else
		game->img->img_player = file_to_img(game, "textures/player_i.xpm");
}
