/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:01:56 by jdagoy            #+#    #+#             */
/*   Updated: 2024/01/18 23:58:40 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line_dda(t_image_data *img, t_point start, \
						t_point end)
{
	int		steps;
	t_point	pixel;
	float	indices[2];

	if (fabsf(end.axis[X] - start.axis[X]) \
			> fabsf(end.axis[Y] - start.axis[Y]))
		steps = fabsf(end.axis[X] - start.axis[X]);
	else
		steps = fabsf(end.axis[Y] - start.axis[Y]);
	indices[X] = (end.axis[X] - start.axis[X]) / steps;
	indices[Y] = (end.axis[Y] - start.axis[Y]) / steps;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	pixel.color = end.color;
	while (steps--)
	{
		my_mlx_pixel_put(img, pixel);
		pixel.axis[X] += indices[X];
		pixel.axis[Y] += indices[Y];
	}
}
