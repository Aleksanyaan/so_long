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
	next_tile = game->map->map[new_y][new_x];
	if (is_blocked(next_tile, game->collectibles))
		return ;
	if (next_tile == 'E' || next_tile == 'M')
		close_window(game);
	if (next_tile == 'C')
		handle_collectible(game, new_x, new_y);
	game->player->x = new_x;
	game->player->y = new_y;
	game->moves++;
	load_player_images(game);
	draw_tile(game, game->img->img_floor, x, y);
	draw_tile(game, game->img->img_player, new_x, new_y);
	show_moves(game); 
}