/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:08:41 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/07 18:53:45 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_tile(t_game *game, void *img, int x, int y)
{
	if (!img)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
				draw_tile(game, game->img->img_wall, x, y);
			else
				draw_tile(game, game->img->img_floor, x, y);
			if (game->map->map[y][x] == 'P')
				draw_tile(game, game->img->img_player, x, y);
			else if (game->map->map[y][x] == 'C')
				draw_tile(game, game->img->img_collectible, x, y);
			else if (game->map->map[y][x] == 'E')
				draw_tile(game, game->img->img_exit, x, y);
			else if (game->map->map[y][x] == 'M')
				draw_tile(game, game->img->img_enemy, x, y);
			x++;
		}
		y++;
	}
}

void	*file_to_img(t_game *game, char *filepath, int *w, int *h)
{
	return (mlx_xpm_file_to_image(game->mlx, filepath, w, h));
}

void	init_images(t_game *game)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	game->img->img_wall = file_to_img(game, "textures/wall.xpm", &w, &h);
	game->img->img_collectible = file_to_img(game, "textures/meat.xpm", &w, &h);
	game->img->img_exit = file_to_img(game, "textures/exit.xpm", &w, &h);
	game->img->img_floor = file_to_img(game, "textures/sand.xpm", &w, &h);
	game->img->img_player = file_to_img(game, "textures/player_i.xpm", &w, &h);
	game->img->img_enemy = file_to_img(game, "textures/enemy.xpm", &w, &h);
	game->img->img_end = NULL;
	if (!game->img->img_wall || !game->img->img_player
		|| !game->img->img_collectible || !game->img->img_floor
		|| !game->img->img_exit)
	{
		write(2, "Error loading image!\n", 22);
		exit(1);
	}
}
