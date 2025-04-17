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
				printf("Invalid character found: %c\n", map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

