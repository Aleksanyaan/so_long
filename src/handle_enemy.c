/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:39:46 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/06 19:59:10 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_next_direction(void)
{
	static int	counter = 0;

	counter++;
	return (counter % 4);
}

void	flip_dir(t_enemy *enemy, int *new_x, int *new_y)
{
	if (enemy->dir == DIR_RIGHT)
		*new_x += 1;
	else if (enemy->dir == DIR_LEFT)
		*new_x -= 1;
	else if (enemy->dir == DIR_DOWN)
		*new_y += 1;
	else if (enemy->dir == DIR_UP)
		*new_y -= 1;
}

void	update_enemy_position(t_game *game, t_enemy *enemy, int new_x,
		int new_y)
{
	char	next_tile;

	if (new_x == game->player->x && new_y == game->player->y)
	{
		write(1, "Caught by enemy!\n", 17);
		close_window(game);
	}
	next_tile = game->map->map[new_y][new_x];
	if (next_tile == '0')
	{
		game->map->map[enemy->y][enemy->x] = '0';
		game->map->map[new_y][new_x] = 'M';
		enemy->x = new_x;
		enemy->y = new_y;
	}
	else
		enemy->dir = get_next_direction();
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	new_x;
	int	new_y;

	if (!game->enemies)
		return ;
	new_x = enemy->x;
	new_y = enemy->y;
	flip_dir(enemy, &new_x, &new_y);
	if (new_x < 0 || new_x >= game->map->width || new_y < 0
		|| new_y >= game->map->height)
	{
		enemy->dir = get_next_direction();
		return ;
	}
	update_enemy_position(game, enemy, new_x, new_y);
	load_enemy_images(game, enemy);
}
