/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:08:26 by zaleksan          #+#    #+#             */
/*   Updated: 2025/04/17 19:58:06 by zaleksan         ###   ########.fr       */
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

void	error_return(int er, int fd, char *temp, char c)
{
	if (er == 1)
	{
		perror("Invalid Map");
		exit(1);
	}
	if (er == 2)
	{
		close (fd);
		printf("Invalid Char found : '%c' \n", c);
		if (temp)
			free(temp);
		exit(1);
	}
	if (er == 3)
	{
		close (fd);
		printf("Invalid Map \n");
		if (temp)
			free(temp);
		exit(1);
	}
}

void	free_matrix(int **mat, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(mat[i++]);
	free(mat);
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

// void	free_map(t_map *map)
// {
// 	if (map)
// 	{
// 		matrix_free(map->mat, map->rc[0]);
// 		free(map);
// 	}
// }