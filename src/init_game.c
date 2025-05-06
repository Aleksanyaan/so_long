/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:02:17 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/06 20:50:19 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct(t_game *game)
{
	game->img->img_wall = NULL;
	game->img->img_floor = NULL;
	game->img->img_exit = NULL;
	game->img->img_collectible = NULL;
	game->img->img_player = NULL;
	game->img->img_enemy = NULL;
	game->img->img_end = NULL;
	game->img->img_width = 0;
	game->img->img_height = 0;
	game->map->map = NULL;
	game->map->x = 0;
	game->map->y = 0;
	game->map->width = 0;
	game->map->height = 0;
	game->player->x = 0;
	game->player->y = 0;
	game->player->dir = 'U';
}

void	init_game(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	game->player = malloc(sizeof(t_player));
	game->img = malloc(sizeof(t_img));
	if (!game->map || !game->player || !game->img)
	{
		free_all(game);
		exit(1);
	}
	init_struct(game);
	game->mlx = NULL;
	game->win = NULL;
	game->enemies = NULL;
	game->enemy_count = 0;
	game->collectibles = 0;
	game->moves = 0;
	game->game_over = 0;
}

void	init_map(t_game *game, char *map)
{
	game->map->map = read_file_to_array(map);
	if (!game->map->map)
	{
		write(1, "Error reading map\n", 18);
		free_all(game);
	}
}

void	init_game_params(t_game *game, char *map)
{
	game->moves = 0;
	game->map->height = count_lines(map);
	game->map->width = ft_strlen(game->map->map[0]);
	game->collectibles = character_count(game, 'C');
	init_player_position(game);
	init_enemies(game);
}
