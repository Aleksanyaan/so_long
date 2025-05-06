/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:02:17 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/06 20:23:40 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	game->player = malloc(sizeof(t_player));
	game->img = malloc(sizeof(t_img));
	if (!game->map || !game->player || !game->img)
		free_all(game);
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
