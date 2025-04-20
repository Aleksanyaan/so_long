/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:08:26 by zaleksan          #+#    #+#             */
/*   Updated: 2025/04/20 17:11:08 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_char(int c)
{
	if (c == '1' || c == '0' || c == 'C'
		|| c == 'P' || c == 'E')
		return (1);
	return (0);
}

char	*trim_newline(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	char_count(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
