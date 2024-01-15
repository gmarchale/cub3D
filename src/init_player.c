/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:24:11 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/15 12:38:55 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	update_player_front(t_player *player)
{
	player->front.dir[X] = cos(player->angle) * 20;
	player->front.dir[Y] = (sin(player->angle) * 20) * -1;
}

void	init_player(t_player *player, int x, int y)
{
	player->position = create_point(x, y);
	player->array_x = x;
	player->array_y = y;
	if (player->direction == 'N')
		player->angle = M_PI_3;
	else if (player->direction == 'S')
		player->angle = M_PI_2;
	else if (player->direction == 'W')
		player->angle = M_PI;
	else
		player->angle = 2 * M_PI;
	update_player_front(player);
}
