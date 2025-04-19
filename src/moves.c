/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:51:42 by zaleksan          #+#    #+#             */
/*   Updated: 2025/04/19 15:51:43 by zaleksan         ###   ########.fr       */
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
		game->map->map[y][x] = '0';
		game->map->map[y][x - 1] = 'P';
		game->player->x -= 1;
		draw_map(game);
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
		game->map->map[y][x] = '0';
		game->map->map[y][x + 1] = 'P';
		game->player->x += 1;
		draw_map(game);
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
		game->map->map[y][x] = '0';
		game->map->map[y - 1][x] = 'P';
		game->player->y -= 1;
		draw_map(game);
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
		game->map->map[y][x] = '0';
		game->map->map[y + 1][x] = 'P';
		game->player->y += 1;
		draw_map(game);
	}
}
