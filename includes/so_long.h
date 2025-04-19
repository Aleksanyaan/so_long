#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>   
# include <stdio.h>  

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"

# define ESC     65307
# define W       119
# define A	    97
# define S	    115
# define D	    100

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
    int     height;
    int     width;
}				t_map;

typedef struct s_palyer
{
	int		x;
	int		y;
    char    *standing;
}				t_player;

typedef struct s_game
{
    void    *mlx;
    void    *win;

    t_map       *map;
    t_player    *player;

    void    *img_player;
    void    *img_wall;
    void    *img_floor;
    void    *img_exit;
    void    *img_collectible;

    int     collectibles;
    int     moves;
}   t_game;


//main.c
void	draw_map(t_game *game);

// init.c
int     count_lines(char *filepath);
char	**read_file_to_array(char *filepath);
void	init_player_position(t_game *game);

//utilities.c
int     check_char(int c);
void	error_return(int er, int fd, char *temp, char c);
char	*trim_newline(char *line);
int     char_count(char **map, char c);
void	free_map(char **map);

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

#endif