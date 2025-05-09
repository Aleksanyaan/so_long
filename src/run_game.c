/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:29 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/09 13:13:56 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_after_move(t_game *game, int old_x, int old_y, int i)
{
	draw_tile(game, game->img->img_floor, old_x, old_y);
	draw_tile(game, game->img->img_enemy, game->enemies[i]->x,
		game->enemies[i]->y);
}

int	game_loop(t_game *game)
{
	int			old_x;
	int			old_y;
	int			i;
	static int	frame = 0;

	i = 0;
	if (frame++ > 40000)
	{
		if (game->enemies)
		{
			while (i < game->enemy_count)
			{
				old_x = game->enemies[i]->x;
				old_y = game->enemies[i]->y;
				move_enemy(game, game->enemies[i]);
				if (game->game_over)
					break ;
				draw_after_move(game, old_x, old_y, i);
				i++;
			}
		}
		frame = 0;
	}
	return (0);
}

void	run(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long");
	if (game->game_over)
		return ;
	init_images(game);
	draw_map(game);
	if (game->enemies)
		mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, handle_input, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}
