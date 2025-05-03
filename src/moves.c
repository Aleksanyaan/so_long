/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:51:42 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/03 14:17:46 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_game *game)
{
	game->player->dir = 'L';
	move_to(game, -1, 0);
}

void	move_right(t_game *game)
{
	game->player->dir = 'R';
	move_to(game, 1, 0);
}

void	move_up(t_game *game)
{
	game->player->dir = 'U';
	move_to(game, 0, -1);
}

void	move_down(t_game *game)
{
	game->player->dir = 'D';
	move_to(game, 0, 1);
}
