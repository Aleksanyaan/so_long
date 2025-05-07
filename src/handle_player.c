/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:27:11 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/07 19:07:49 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'P')
			{
				game->player->x = j;
				game->player->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	load_player_images(t_game *game)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	if (game->img->img_player)
		mlx_destroy_image(game->mlx, game->img->img_player);
	if (game->player->dir == 'L')
		game->img->img_player = file_to_img(game, "textures/player_l.xpm", &w,
				&h);
	else if (game->player->dir == 'R')
		game->img->img_player = file_to_img(game, "textures/player_r.xpm", &w,
				&h);
	else if (game->player->dir == 'U')
		game->img->img_player = file_to_img(game, "textures/player_b.xpm", &w,
				&h);
	else
		game->img->img_player = file_to_img(game, "textures/player_i.xpm", &w,
				&h);
}

int	handle_next_tile(t_game *game, int new_x, int new_y)
{
	char	next_tile;

	next_tile = game->map->map[new_y][new_x];
	if (is_blocked(next_tile, game->collectibles))
		return (1);
	if (next_tile == 'E')
		display_end_game(game, "textures/win.xpm");
	else if (next_tile == 'M')
		display_end_game(game, "textures/lose.xpm");
	if (next_tile == 'C')
	{
		game->collectibles--;
		game->map->map[new_y][new_x] = '0';
	}
	return (0);
}

void	move_to(t_game *game, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;

	x = game->player->x;
	y = game->player->y;
	new_x = x + x_offset;
	new_y = y + y_offset;
	if (handle_next_tile(game, new_x, new_y) || game->game_over)
		return ;
	game->player->x = new_x;
	game->player->y = new_y;
	game->moves++;
	load_player_images(game);
	draw_tile(game, game->img->img_floor, x, y);
	draw_tile(game, game->img->img_player, new_x, new_y);
	show_moves(game);
}
