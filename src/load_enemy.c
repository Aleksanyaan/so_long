/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:19:50 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/07 19:01:32 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_enemy(t_game *game, int x, int y, int i)
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
}

void	get_enemy_position(t_game *game)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'M')
			{
				init_enemy(game, x, y, i);
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_enemies(t_game *game)
{
	int	count;

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
		exit(1);
	}
	get_enemy_position(game);
	game->enemy_count = count;
}

void	load_enemy_images(t_game *game, t_enemy *enemy)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	if (!game->enemies || game->game_over)
		return ;
	if (game->img->img_enemy)
		mlx_destroy_image(game->mlx, game->img->img_enemy);
	if (enemy->dir == DIR_LEFT)
		game->img->img_enemy = file_to_img(game, "textures/enemy_l.xpm", &w,
				&h);
	else if (enemy->dir == DIR_RIGHT)
		game->img->img_enemy = file_to_img(game, "textures/enemy_r.xpm", &w,
				&h);
	else if (enemy->dir == DIR_UP)
		game->img->img_enemy = file_to_img(game, "textures/enemy_up.xpm", &w,
				&h);
	else
		game->img->img_enemy = file_to_img(game, "textures/enemy.xpm", &w, &h);
}
