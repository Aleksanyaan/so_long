/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:22:37 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/07 20:08:08 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || !is_ber_file(argv[1]))
	{
		write(1, "Error: Enter a .ber file!\n", 27);
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	init_game(game);
	init_map(game, argv[1]);
	init_game_params(game, argv[1]);
	if (!is_map_valid(game))
	{
		write(1, "Error: Map is not valid!\n", 25);
		free_map(game->map->map);
		free_all(game);
		return (1);
	}
	run(game);
	close_window(game);
}
