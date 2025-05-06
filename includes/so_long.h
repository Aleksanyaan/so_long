/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:46:01 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/06 20:21:18 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define TILE_SIZE 64
# define DIR_RIGHT 0
# define DIR_LEFT 1
# define DIR_DOWN 2
# define DIR_UP 3
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
	int			height;
	int			width;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	char		dir;
}				t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			dir;
}				t_enemy;

typedef struct s_img
{
	void		*img_wall;
	void		*img_floor;
	void		*img_exit;
	void		*img_collectible;
	void		*img_player;
	void		*img_enemy;
	void		*img_end;

	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_fill
{
	char		**map;
	int			width;
	int			height;
	int			collectibles_found;
	int			exits_found;
}				t_fill;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	t_map		*map;
	t_img		*img;
	t_player	*player;
	t_enemy		**enemies;

	int			collectibles;
	int			moves;
	int			enemy_count;
	int			game_over;
}				t_game;

// is_valid.c
int				is_map_valid(t_game *game);
int				is_ber_file(char *filename);

// init_game.c
void			init_game(t_game *game);
void			init_map(t_game *game, char *map);
void			init_game_params(t_game *game, char *map);

// free.c
void			free_map(char **map);
void			free_all(t_game *game);
void			free_enemies(t_game *game);
void			cleanup(t_game *game);

// draw.c
void			draw_map(t_game *game);
void			draw_tile(t_game *game, void *img, int x, int y);
void			init_images(t_game *game);
void			*file_to_img(t_game *game, char *filepath, int *w, int *h);

// handle_input.c
int				handle_input(int keycode, t_game *game);
int				close_window(t_game *game);
int				is_blocked(char tile, int collectibles);
void			show_moves(t_game *game);

// init_map.c
int				count_lines(char *filepath);
char			**read_file_to_array(char *filepath);
void			init_player_position(t_game *game);

// utilities.c
int				check_char(int c);
char			*trim_newline(char *line);
int				char_count(char **map, char c);
int				character_count(t_game *game, char c);

// map_validation.c
int				check_rectangular(char **map);
int				check_char_count(char **map);
int				check_valid_chars(char **map);
int				check_is_map_surrounded_by_walls(char **map);

// valid_path.c
int				valid_path(t_game *game);

// moves.c
void			move_left(t_game *game);
void			move_right(t_game *game);
void			move_up(t_game *game);
void			move_down(t_game *game);

// handle_player.c
void			load_player_images(t_game *game);
void			move_to(t_game *game, int x_offset, int y_offset);

// handle_enemy.c
void			move_enemy(t_game *game, t_enemy *enemy);
int				get_next_direction(void);

// load_enemy.c
void			init_enemies(t_game *game);
void			load_enemy_images(t_game *game, t_enemy *enemy);

// end_window.c
void			display_end_game(t_game *game, char *image_path);

// run_game.c
void			run(t_game *game);
#endif