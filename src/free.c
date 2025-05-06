/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:09:53 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/06 17:46:49 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_enemies(t_game *game)
{
	int	i;

	if (!game->enemies)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i])
			free(game->enemies[i]);
		i++;
	}
	free(game->enemies);
	game->enemies = NULL;
}

void	free_all(t_game *game)
{
	if (!game)
		exit(1);
	free(game->map);
	free(game->player);
	free(game->img);
	free_enemies(game);
	free(game);
}

void	cleanup(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img_wall);
	mlx_destroy_image(game->mlx, game->img->img_floor);
	mlx_destroy_image(game->mlx, game->img->img_player);
	mlx_destroy_image(game->mlx, game->img->img_exit);
	mlx_destroy_image(game->mlx, game->img->img_collectible);
	mlx_destroy_image(game->mlx, game->img->img_enemy);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
