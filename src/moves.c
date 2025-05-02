/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:51:42 by zaleksan          #+#    #+#             */
/*   Updated: 2025/04/30 20:58:58 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_game *game)
{
	game->player->dir = 'L';
	// load_player_images(game);
	move_to(game, -1, 0);
}

void	move_right(t_game *game)
{
	game->player->dir = 'R';
	// load_player_images(game);
	move_to(game, 1, 0);
}

void	move_up(t_game *game)
{
	game->player->dir = 'U';
	// load_player_images(game);
	move_to(game, 0, -1);
}

void	move_down(t_game *game)
{
	game->player->dir = 'D';
	// load_player_images(game);
	move_to(game, 0, 1);
}
