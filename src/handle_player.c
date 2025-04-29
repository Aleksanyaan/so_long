#include "../includes/so_long.h"

char	*build_path(const char *dir, const char *prefix, int frame)
{
	char	*frame_str;
	char	*partial;
	char	*full;

	frame_str = ft_itoa(frame);
	partial = ft_strjoin((char *)prefix, frame_str);
    full = ft_strjoin((char *)partial, ".xpm");
	free(partial);
	partial = ft_strjoin((char *)dir, full);
	free(frame_str);
	free(full);
	return (partial);
}

void	load_player_images(t_game *game)
{
	int		i;
	int		w;
	int		h;
	char	*path;

	for (i = 0; i < 4; i++)
	{
		path = build_path("textures/player/idle_l/", "idle", i);
		game->img->player_left[i] = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
		free(path);

		path = build_path("textures/player/idle_r/", "idle", i);
		game->img->player_right[i] = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
		free(path);
	}
}
