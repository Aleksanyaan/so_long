/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:43:46 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/07 21:03:55 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	cleanup(game);
	free_map(game->map->map);
	free_all(game);
	exit(0);
}

int	is_blocked(char tile, int collectibles)
{
	if (tile == '1')
		return (1);
	if (tile == 'E' && collectibles > 0)
		return (1);
	return (0);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == W)
		move_up(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == S)
		move_down(game);
	else if (keycode == D)
		move_right(game);
	return (0);
}

void	show_moves(t_game *game)
{
	char	*count_str;
	char	*display_str;

	count_str = ft_itoa(game->moves);
	display_str = ft_strjoin("Moves: ", count_str);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, display_str);
	free(count_str);
	free(display_str);
}
