/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:23:41 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/04 16:23:41 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_put.h"

void	mlx_img_pixel_put(t_globals *globals, t_vector2int position,
		unsigned int color)
{
	unsigned int	*dst;

	if (position.x <= 0 || WIDTH <= position.x
		|| position.y <= 0 || HEIGHT <= position.y)
		return ;
	dst = (void *)globals->mlx.img.addr
		+ (position.y * globals->mlx.img.line_length) + (position.x * 4);
	*dst = color;
}

void	mlx_img_square_put(t_globals *globals, t_vector2int top_left_position,
		t_vector2int dimension, unsigned int color)
{
	t_vector2int	position;

	position = top_left_position;
	while (position.y - top_left_position.y < dimension.y)
	{
		while (position.x - top_left_position.x < dimension.x)
		{
			mlx_img_pixel_put(globals, position, color);
			position.x++;
		}
		position.x = top_left_position.x;
		position.y++;
	}
}
