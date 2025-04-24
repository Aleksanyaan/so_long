#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>   
# include <stdio.h>  

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# define TILE_SIZE  64
# define ESC        65307
# define W          119
# define A	        97
# define S	        115
# define D	        100

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
    int     height;
    int     width;
}   t_map;

typedef struct s_palyer
{
	int		x;
	int		y;
    char    *standing;
}   t_player;

typedef struct s_img
{
    void    *img_player;
    void    *img_wall;
    void    *img_floor;
    void    *img_exit;
    void    *img_collectible;
}   t_img;

typedef struct s_game
{
    void    *mlx;
    void    *win;

    t_map       *map;
    t_player    *player;
    t_img       *img;

    int     collectibles;
    int     moves;
}   t_game;

// free.c
void	free_map(char **map);
void    free_all(t_game *game);
void	cleanup(t_game *game);

// draw.c
void	draw_map(t_game *game);
void	draw_tile(t_game *game, void *img, int x, int y);
void    init_images(t_game *game);

// handle_input.c
int	handle_input(int keycode, t_game *game);
int	close_window(t_game *game);
void	show_moves(t_game *game);

// init.c
int     count_lines(char *filepath);
char	**read_file_to_array(char *filepath);
void	init_player_position(t_game *game);

//utilities.c
int     check_char(int c);
void	error_return(int er, int fd, char *temp, char c);
char	*trim_newline(char *line);
int     char_count(char **map, char c);

//map_validation.c
int	    check_rectangular(char **map);
int	    check_char_count(char **map);
int	    check_valid_chars(char **map);
int	    check_is_map_surrounded_by_walls(char **map);


// moves.c
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);

// handle_collectibles.c
int     collectible_count(t_game *game);
void	move_to(t_game *game, int x_offset, int y_offset);

#endif