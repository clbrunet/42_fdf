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

void	mlx_img_pixel_put(t_img *img, t_vector2int position,
		unsigned int color)
{
	unsigned int	*dst;

	if (position.x <= 0 || WIDTH <= position.x
		|| position.y <= 0 || HEIGHT <= position.y)
		return ;
	dst = (void *)img->addr
		+ (position.y * img->line_length) + (position.x * 4);
	*dst = color;
}

void	mlx_img_square_put(t_img *img, t_vector2int top_left_position,
		t_vector2int dimension, unsigned int color)
{
	t_vector2int	position;

	position = top_left_position;
	while (position.y - top_left_position.y < dimension.y)
	{
		while (position.x - top_left_position.x < dimension.x)
		{
			mlx_img_pixel_put(img, position, color);
			position.x++;
		}
		position.x = top_left_position.x;
		position.y++;
	}
}

void	mlx_img_line_put(t_img *img, t_vector2int from, t_vector2int to,
		unsigned int color)
{
	int	delta_x;
	int	delta_y;

	delta_x = ft_abs(to.x - from.x);
	delta_y = ft_abs(to.y - from.y);
	if (from.y == to.y)
	{
		mlx_img_horizontal_line_put(img, from, to, color);
	}
	else if (from.x == to.x)
	{
		mlx_img_vertical_line_put(img, from, to, color);
	}
	else if (delta_y > delta_x)
	{
		mlx_img_rise_line_put(img, from, to, color);
	}
	else
	{
		mlx_img_run_line_put(img, from, to, color);
	}
}
