#include "../includes/so_long.h"

int	count_lines(char *filepath)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error_return(1, 0, NULL, 0);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (count);
}

char	**read_file_to_array(char *filepath)
{
	char	**lines;
	char	*line;
	int		total;
	int		i;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error_return(1, 0, NULL, 0);
	total = count_lines(filepath);
	if (total < 0)
		return (NULL);
	lines = malloc((total + 1) * sizeof(int *));
	if (!lines || fd < 0)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (i < total && line != NULL)
	{
		lines[i++] = trim_newline(line);
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close (fd);
	return (lines);
}

void	init_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'P')
			{
				game->player->x = j;
				game->player->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
