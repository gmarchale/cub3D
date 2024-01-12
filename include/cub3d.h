#ifndef CUB3D_H
# define CUB3D_H

# include "../src/Libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "struct.h"
# include "enums.h"

# define PI 3.1415

# define WHITE 0xFFFFFF
# define RED 0xFF0000

# define WIN_WIDTH 1500
# define WIN_HEIGHT 1300

# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define X_AXIS 0
# define Y_AXIS 1

/* Hooks */
void	ft_mlx_hooks(t_display *display);
int		close_window(int keycode, t_display *display);
int	close_window_cross(t_display *display);
void	init_mlx(t_display *display, t_image_data *img);
void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color);

/* Parsing */
int	parsing(int argc, char **argv, t_game *game);

/* Init */
t_game *init_game(t_game *game);

/* Texture */
void	get_texture(t_texture *texture, char *line);

/* Check Map */
//int	check_open_map(char **map);
int check_borders_horizontal(char **map);
void check_wall_map(char **map, int y, int x);

/* Utils */
int	len_split(char **split);
int	rgb_to_hex(int red, int green, int blue);
char	*skip_empty_line(int fd, char *line);

#endif
