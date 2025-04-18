#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>   
# include <stdio.h>  

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"

// init.c
char	**read_file_to_array(char *filepath);

//utilities.c
int     check_char(int c);
void	free_matrix(int **mat, int rows);
void	error_return(int er, int fd, char *temp, char c);
char	*trim_newline(char *line);
int     char_count(char **map, char c);


// void	free_map(t_map *map);

//map_validation.c
int	check_rectangular(char **map);
int	check_valid_chars(char **map);
int	check_char_count(char **map);
int	check_is_map_surrounded_by_walls(char **map);


#endif