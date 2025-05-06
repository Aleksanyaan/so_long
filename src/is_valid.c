/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:13:50 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/06 20:13:51 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_map_valid(t_game *game)
{
	if (!check_valid_chars(game->map->map) || !check_char_count(game->map->map)
		|| !valid_path(game) || !check_rectangular(game->map->map)
		|| !check_is_map_surrounded_by_walls(game->map->map))
		return (0);
	return (1);
}

int	is_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}
