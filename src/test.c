#include "../includes/so_long.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }
// 				t_data;
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void ft_draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
// {
//     int step;
//     int x;
//     int y;
//     int i;
//     int delta_x;
//     int delta_y;
    
//     delta_x = x2 - x1;
//     delta_y = y2 - y1;
//     if (abs(delta_x) >= abs(delta_y))
//         step = abs(delta_x);
//     else
//         step = abs(delta_y);
//     delta_x = delta_x / step;
//     delta_y = delta_y / step;
//     x = x1;
//     y = x2;
//     i = 0;
//     while (i < step)
//     {
//         my_mlx_pixel_put(data, x, y, color);
//         x += delta_x;
//         y += delta_y;
//         i++;
//     }
// }

// int wall = -1;

// void flood_fill(int pos_x, int pos_y, int target_color, int color)
// {

//    if(a[pos_x][pos_y] == wall || a[pos_x][pos_y] == color) // if there is no wall or if i haven't been there
//       return;                                              // already go back

//    if(a[pos_x][pos_y] != target_color) // if it's not color go back
//       return;

//    a[pos_x][pos_y] = color; // mark the point so that I know if I passed through it. 

//    flood_fill(pos_x + 1, pos_y, color);  // then i can either go south
//    flood_fill(pos_x - 1, pos_y, color);  // or north
//    flood_fill(pos_x, pos_y + 1, color);  // or east
//    flood_fill(pos_x, pos_y - 1, color);  // or west

//    return;

// }

#define ESC     53
#define W       13
#define A	    0
#define S	    1
#define D	    2

typedef struct s_vars{
    void    *mlx;
    void    *win;
    int     x;
    int     y;
    int     box_x;
    int     box_y;
}t_vars;

int render_square(t_vars *vars)
{
    int x;
    int y;

    x = 350;
    y = 350;
    mlx_clear_window(vars->mlx, vars->win);
    while(x < 450)
    {
        while(y < 450)
        {
        mlx_pixel_put(vars->mlx, vars->win, x + vars->x, y + vars->y, 0xFFDDFF);
        y++;
    }
    y = 350;
    x++;
    }
    mlx_do_sync(vars->mlx);
    return(1);
}

int quit(int keycode, t_vars *vars)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        free(vars);
        exit(0);
    }
    return(0);
}

int keys(int keycode, t_vars *vars)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        free(vars);
        exit(0);
    }
    if (keycode == W)
        vars->box_y -= 10;
    if (keycode == A)
        vars->box_x -= 10;
    if (keycode == S)
        vars->box_y += 10;
    if (keycode == D)
        vars->box_x += 10;
    return(0);
}

// int main()
// {
//     t_vars  *vars;

//     vars = NULL;
//     vars = malloc(sizeof(t_vars));

//     vars->mlx = mlx_init();
//     vars->win = mlx_new_window(vars->mlx, 1920 , 1080 , "HELLO");

    

//     mlx_hook(vars->win, 2, 0, quit, vars);
//     render_square(vars);
//     mlx_loop(vars->mlx);
// }

