#include "../includes/so_long.h"

int	is_map_valid(char **map)
{
	if(!check_valid_chars(map) || !check_char_count(map)
		|| !check_rectangular(map) || !check_is_map_surrounded_by_walls(map))
		return (0);
	return (1);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 64, y * 64);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * 64, y * 64);
			if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 64, y * 64);
			else if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * 64, y * 64);
			else if (game->map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		close_window(game);
	}
	else if (keycode == W)
	{
		move_up(game);
		write(1, "Move Up\n", 8);
	}
	else if (keycode == A)
	{
		move_left(game);
		write(1, "Move Left\n", 10);
	}
	else if (keycode == S)
	{
		move_down(game);
		write(1, "Move Down\n", 10);
	}
	else if (keycode == D)
	{
		move_right(game);
		write(1, "Move Right\n", 11);
	}
	return (0);
}

void	run(t_game *game)
{
	int w, h;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * 64, game->map->height * 64, "so_long");

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player_floor.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/meat_floor.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
	if (!game->img_wall || !game->img_player || !game->img_collectible || !game->img_floor || !game->img_exit)
	{
		write(1, "Error loading image!\n", 21);
		exit(1);
	}
	draw_map(game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_hook(game->win, 17, 0, close_window, game); 
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	if (argc != 2)
	{
		printf("Usage: %s <map.ber>\n", argv[0]);
		return (1);
	}

	map.map = read_file_to_array(argv[1]);

	if (!map.map)
	{
		printf("Error reading map\n");
		return (1);
	}
	game.map = malloc(sizeof(t_map));
	game.player = malloc(sizeof(t_player));

	if (!game.map || !game.player)
		exit(1);

	if (!is_map_valid(map.map))
	{
		write(1, "Error: Map is not valid!\n", 25);
		free_map(map.map);
		return (1);
	}

	// Initialize the game struct properly
	game.map = &map;  // Assign map to game struct
	map.height = count_lines(argv[1]);
	map.width = ft_strlen(map.map[0]);
	init_player_position(&game);
	run(&game);

	free_map(map.map);
	system("leaks a.out");
	return (0);
}
