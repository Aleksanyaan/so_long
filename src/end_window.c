/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:43:57 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/06 19:43:58 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_end_game(t_game *game, char *image_path)
{
	game->game_over = 1;
	mlx_clear_window(game->mlx, game->win);
	game->img->img_end = mlx_xpm_file_to_image(game->mlx, image_path,
			&game->img->img_width, &game->img->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_end,
		(game->map->width * TILE_SIZE - game->img->img_width) / 2,
		(game->map->height * TILE_SIZE - game->img->img_height) / 2);
}
