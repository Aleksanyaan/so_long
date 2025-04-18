#include "../includes/so_long.h"

int	is_map_valid(char **map)
{
	if(!check_valid_chars(map) || !check_char_count(map)
		|| !check_rectangular(map) || !check_is_map_surrounded_by_walls(map))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
	{
		printf("Usage: %s <map.ber>\n", argv[0]);
		return (1);
	}

	map = read_file_to_array(argv[1]);

	if (!map)
	{
		printf("Error reading map\n");
		return (1);
	}

	if (!is_map_valid(map))
	{
		write(1, "Error: Map is not valid!\n", 25);
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		return (1);
	}
		
	// i = 0;
	// while(map[i] != NULL)
	// {
	// 	printf("%s", map[i]);
	// 	i++;
	// }
	// Free memory
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	system("leaks a.out");
	return (0);
}
