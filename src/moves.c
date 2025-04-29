/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:51:42 by zaleksan          #+#    #+#             */
/*   Updated: 2025/04/29 16:38:12 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_game *game)
{
	game->player->dir = 'L';
	game->player->frame = (game->player->frame + 1) % 4;
	move_to(game, -1, 0);
}

void	move_right(t_game *game)
{
	game->player->dir = 'R';
	game->player->frame = (game->player->frame + 1) % 4;
	move_to(game, 1, 0);
}

void	move_up(t_game *game)
{
	move_to(game, 0, -1);
}

void	move_down(t_game *game)
{
	move_to(game, 0, 1);
}
