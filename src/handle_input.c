/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:43:46 by zaleksan          #+#    #+#             */
/*   Updated: 2025/04/20 13:43:47 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == W)
	{
		move_up(game);
		ft_putnbr_fd(game->moves, 1);
	}
	else if (keycode == A)
	{
		move_left(game);
		ft_putnbr_fd(game->moves, 1);
	}
	else if (keycode == S)
	{
		move_down(game);
		ft_putnbr_fd(game->moves, 1);
	}
	else if (keycode == D)
	{
		move_right(game);
		ft_putnbr_fd(game->moves, 1);
	}
	return (0);
}
