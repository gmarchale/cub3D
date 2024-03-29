/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:51:52 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/23 19:22:08 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "struct.h"
# include "enums.h"

# define TILE_SIZE 64
# define WIN_WIDTH 1280
# define WIN_HEIGHT 900
# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define X 0
# define Y 1
# define M_PI_3 4.71238898038  //3 *PI/2
# define FOV 1.0471975512 // M_PI /3
# define DEGINRAD 0.0174533
# define MOVE_SPEED 1.5

/* Hooks */
int			keybindings(int keycode, t_game *game);
int			close_window_cross(t_game *game);

/* Parsing */
int			parsing(int argc, char **argv, t_game *game);

/* Init */
t_game		*init_game(t_game *game);

/* Texture */
int			get_texture(t_game *game, t_texture *texture, char *line);

/* Check Map */
int			check_borders_horizontal(char **map);
void		check_wall_map(char **map, int y, int x);

/* Check Utils */
int			check_all_textures(t_texture *texture);
int			check_char(char c);
void		check_char_map(t_game *game, char **map, t_player *player);
void		replace_threes(char **map);

/* Check Colors */
int			check_color(t_game *game, int color);
void		check_atoi(t_game *game, char *color, int atoi_color);
int			check_rgb(t_game *game, char *red, char *green, char *blue);

/* Utils */
int			len_split(char **split);
int			rgb_to_hex(t_game *game, int red, int green, int blue);
float		deg_to_rad(float degrees);
char		*skip_empty_line(int fd, char *line);
char		*next_line(int fd, char *line);

// mlx
int			init_mlx(t_display *mlx);
void		my_mlx_pixel_put(t_image_data *img, t_point pixel);

// calc_mapdimensions.c
void		calc_mapdimensions(t_game *game);

// create_vectorpoint.c
t_point		create_point(float x, float y, int color);
t_vector	create_vector(float x, float y);

// draw_3d.c
void		draw_3d(t_game *game, int raynum);

// draw_3d_utils.c
float		fix_fisheye(t_game *game);
float		check_rayhit(t_game *game, float x);
int			get_direction(t_game *game);

// draw_map.c
int			draw_map(t_game *game);

// get_textures.c
void		get_textures(t_game *game);
int			count_commas(char *string);
int			checkspace(char *line);

// init_player.c
void		update_player_front(t_player *player);
void		init_player(t_game *game);

// set_color.c
void		set_color(char *buffer, int endian, int color, int alpha);

// raycaster_angles.c
void		set_horizontal_angle(t_game *game, float arc_tan);
void		set_vertical_angle(t_game *game, float tangent);

// raycaster_castrays.c
void		cast_horizontal_rays(t_game *game);
void		cast_vertical_rays(t_game *game);

// raycaster.c
float		get_distance(float x1, float y1, float x2, float y2);
void		draw_ray(t_game *game);

// movement_utils.c
void		cal_side_direction(t_vector *front, t_vector *side);
int			check_playerpos(t_game *game);
int			offset_check(t_game *game, char *type, int value);

// movement_y.c
void		player_movement_y(int keycode, t_game *game);

// movement_x.c
void		player_movement_x(int keycode, t_game *game);

// free.c
void		free_all(t_game *game);
int			error_manager(t_game *game, char *error_msg);
void		ft_freesplit(char **tab);

// process_map.c
int			process_map(t_game *game, char **map);

#endif
