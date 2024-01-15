/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/15 12:58:56 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_map(char **map)
{
	int i, j;
	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
int	main(int argc, char **argv)
{
	t_game			game;
	t_display		mlx;
	char			*testmap[] = {
        "111111111111111",
        "100000000000101",
        "100001000000101",
        "111100000010101",
        "100000000030101",
        "100000001111101",
        "100000000000001",
        "100000000000001",
        "111311000111101",
        "100000000000001",
        "111111111111111"
    };
	t_texture		texture;

	(void)argc;
	(void)argv;
	game.map = testmap;
	game.map_height = 11;
	game.map_width = 15;
	game.floor_color = 0x6F8FAF;
	game.ceiling_color = 0x0000FF;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIN_WIDTH, \
				WIN_HEIGHT, "cub3D");
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.address = mlx_get_data_addr(mlx.img.img,
			&mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	game.display = mlx;
	texture.north = "./texture/brick_red.xpm";
	texture.south = "./texture/test.xpm";
	texture.east = "./texture/brick_gray.xpm";
	texture.west = "./texture/brick_graymoss.xpm";
	read_textures(&game, &mlx, texture.north, "NORTH");
	read_textures(&game, &mlx, texture.south, "SOUTH");
	read_textures(&game, &mlx, texture.east, "EAST");
	read_textures(&game, &mlx, texture.west, "WEST");
	init_player(&game);
	mlx_hook(game.display.window, ON_KEYDOWN, 1L << 0, keybindings, &game);
	mlx_hook(game.display.window, ON_DESTROY, 1L << 0, close_window_cross, &mlx);
	mlx_loop_hook(game.display.mlx, &draw_map, &game);
	mlx_loop(mlx.mlx);
	return (0);
}
