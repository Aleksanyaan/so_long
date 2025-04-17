#include "../includes/so_long.h"

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

	if (!check_valid_chars(map))
	{
		printf("Error: Map is not rectangular\n");
		i = 0;
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		return (1);
	}
	else 
		printf("1");

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
