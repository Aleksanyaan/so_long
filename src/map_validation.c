/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:13:41 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/07 21:05:44 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_rectangular(char **map)
{
	int		i;
	size_t	first_len;

	if (!map || !map[0])
		return (0);
	first_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_len)
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_char(map[i][j]))
			{
				write(1, "Invalid character found!", 24);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_char_count(char **map)
{
	if (char_count(map, 'E') != 1 || char_count(map, 'P') != 1
		|| char_count(map, 'C') < 1 || char_count(map, 'M') > 8)
		return (0);
	return (1);
}

int	check_is_map_surrounded_by_walls(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j++] != '1')
			return (0);
	}
	i = 1;
	while (map[i + 1])
	{
		j = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j++] != '1')
			return (0);
	}
	return (1);
}
