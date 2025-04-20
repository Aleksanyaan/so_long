#include "../includes/so_long.h"

int	is_map_valid(char **map)
{
	if(!check_valid_chars(map) || !check_char_count(map)
		|| !check_rectangular(map) || !check_is_map_surrounded_by_walls(map))
		return (0);
	return (1);
}

void	cleanup(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img_wall);
	mlx_destroy_image(game->mlx, game->img->img_floor);
	mlx_destroy_image(game->mlx, game->img->img_player);
	mlx_destroy_image(game->mlx, game->img->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx); // only on Linux
	free(game->mlx);
}


void	run(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * TILE_SIZE, game->map->height * TILE_SIZE, "so_long");

	init_images(game);
	draw_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_input, game);
	mlx_hook(game->win, 17, 0, close_window, game); 
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		printf("Usage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		exit (1);
	game->moves = 0;
	game->map = malloc(sizeof(t_map));
	game->player = malloc(sizeof(t_player));
	game->img = malloc(sizeof(t_img));
	if (!game->map || !game->player || !game->img)
		free_all(game);
	game->map->map = read_file_to_array(argv[1]);
	
	if (!game->map->map)
	{
		printf("Error reading map\n");
		free_all(game);
	}

	if (!is_map_valid(game->map->map))
	{
		write(1, "Error: Map is not valid!\n", 25);
		free_map(game->map->map);
		free_all(game);
	}

	game->map->height = count_lines(argv[1]);
	game->map->width = ft_strlen(game->map->map[0]);
	init_player_position(game);
	run(game);

	cleanup(game);
	free_map(game->map->map);
	free_all(game);
	exit(1);
	system("leaks a.out");
	return (0);
}
