/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:43:57 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/06 21:02:02 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_end_game(t_game *game, char *image_path)
{
	if (game->img->img_end)
		mlx_destroy_image(game->mlx, game->img->img_end);
	game->game_over = 1;
	mlx_clear_window(game->mlx, game->win);
	game->img->img_end = mlx_xpm_file_to_image(game->mlx, image_path,
			&game->img->img_width, &game->img->img_height);
	if (!game->img->img_end)
	{
		write(2, "Error loading end game image!\n", 30);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_end,
		(game->map->width * TILE_SIZE - game->img->img_width) / 2,
		(game->map->height * TILE_SIZE - game->img->img_height) / 2);
}
