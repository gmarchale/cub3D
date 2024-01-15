/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/15 13:02:23 by jdagoy           ###   ########.fr       */
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

	parsing(argc, argv, &game);
	print_map(game.map);
	init_mlx(&game.display);
	get_textures(&game);
	mlx_hook(game.display.window, ON_KEYDOWN, 1L << 0, keybindings, &game);
	mlx_hook(game.display.window, ON_DESTROY, 1L << 0, close_window_cross, &game.display);
	mlx_loop_hook(game.display.mlx, &draw_map, &game);
	mlx_loop(game.display.mlx);
	return (0);
}
