/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/23 19:23:03 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game			game;

	parsing(argc, argv, &game);
	calc_mapdimensions(&game);
	if (process_map(&game, game.map) != 0)
		error_manager(&game, "Calloc error");
	if (init_mlx(&game.display) != 0)
		error_manager(&game, "MLX initialization failed");
	get_textures(&game);
	init_player(&game);
	mlx_hook(game.display.window, ON_KEYDOWN, 1L << 0, keybindings, &game);
	mlx_hook(game.display.window, ON_DESTROY, 1L << 0, \
				close_window_cross, &game);
	mlx_loop_hook(game.display.mlx, &draw_map, &game);
	mlx_loop(game.display.mlx);
	return (EXIT_SUCCESS);
}
