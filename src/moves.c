/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:51:42 by zaleksan          #+#    #+#             */
/*   Updated: 2025/04/20 14:19:22 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y][x - 1] != '1')
	{
		game->player->x -= 1;
		game->moves++;
		draw_tile(game, game->img->img_player, x - 1, y);
		draw_tile(game, game->img->img_floor, x, y);
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y][x + 1] != '1')
	{
		game->player->x += 1;
		game->moves++;
		draw_tile(game, game->img->img_player, x + 1, y);
		draw_tile(game, game->img->img_floor, x, y);
	}
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y - 1][x] != '1')
	{
		game->player->y -= 1;
		game->moves++;
		draw_tile(game, game->img->img_player, x, y - 1);
		draw_tile(game, game->img->img_floor, x, y);
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->map->map[y + 1][x] != '1')
	{
		game->player->y += 1;
		game->moves++;
		draw_tile(game, game->img->img_player, x, y + 1);
		draw_tile(game, game->img->img_floor, x, y);
	}
}
