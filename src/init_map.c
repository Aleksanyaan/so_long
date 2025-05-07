/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:13:20 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/07 20:05:22 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	line_len(char *filepath)
{
	char	*line;
	int		len;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line);
	free(line);
	close(fd);
	return (len);
}

int	count_lines(char *filepath)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_file_to_array(char *filepath)
{
	char	**lines;
	char	*line;
	int		total;
	int		i;
	int		fd;

	total = count_lines(filepath);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc((total + 1) * sizeof(char *));
	if (!lines)
		return (close(fd), NULL);
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (free(lines), NULL);
	while (line)
	{
		lines[i++] = trim_newline(line);
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}
