/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_put2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:16:41 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/10 09:16:41 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_put.h"

void	mlx_img_horizontal_line_put(t_img *img, t_vector2int from,
		t_vector2int to, unsigned int color)
{
	t_vector2int	position;
	int				increment_x;

	increment_x = 1;
	if (to.x < from.x)
	{
		increment_x = -1;
	}
	position.x = from.x;
	position.y = from.y;
	while (position.x != to.x)
	{
		mlx_img_pixel_put(img, position, color);
		position.x += increment_x;
	}
	mlx_img_pixel_put(img, to, color);
}

void	mlx_img_vertical_line_put(t_img *img, t_vector2int from,
		t_vector2int to, unsigned int color)
{
	t_vector2int	position;
	int				increment_y;

	increment_y = 1;
	if (to.y < from.y)
	{
		increment_y = -1;
	}
	position.x = from.x;
	position.y = from.y;
	while (position.y != to.y)
	{
		mlx_img_pixel_put(img, position, color);
		position.y += increment_y;
	}
	mlx_img_pixel_put(img, to, color);
}

static void	mlx_img_line_put_set_increment(t_vector2int *increment,
		t_vector2int from, t_vector2int to)
{
	if (to.x < from.x)
	{
		increment->x = -1;
	}
	else
	{
		increment->x = 1;
	}
	if (to.y < from.y)
	{
		increment->y = -1;
	}
	else
	{
		increment->y = 1;
	}
}

void	mlx_img_rise_line_put(t_img *img, t_vector2int from,
		t_vector2int to, unsigned int color)
{
	t_vector2int	delta;
	t_vector2int	position;
	t_vector2int	increment;
	int				d;

	delta.x = ft_abs(to.x - from.x);
	delta.y = ft_abs(to.y - from.y);
	position.x = from.x;
	position.y = from.y;
	mlx_img_line_put_set_increment(&increment, from, to);
	d = 2 * delta.x - delta.y;
	while (position.y != to.y)
	{
		mlx_img_pixel_put(img, position, color);
		position.y += increment.y;
		if (d < 0)
			d += 2 * delta.x;
		else
		{
			position.x += increment.x;
			d += 2 * delta.x - 2 * delta.y;
		}
	}
	mlx_img_pixel_put(img, to, color);
}

void	mlx_img_run_line_put(t_img *img, t_vector2int from, t_vector2int to,
		unsigned int color)
{
	t_vector2int	delta;
	t_vector2int	position;
	t_vector2int	increment;
	int				d;

	delta.x = ft_abs(to.x - from.x);
	delta.y = ft_abs(to.y - from.y);
	position.x = from.x;
	position.y = from.y;
	mlx_img_line_put_set_increment(&increment, from, to);
	d = 2 * delta.y - delta.x;
	while (position.x != to.x)
	{
		mlx_img_pixel_put(img, position, color);
		position.x += increment.x;
		if (d < 0)
			d += 2 * delta.y;
		else
		{
			position.y += increment.y;
			d += 2 * delta.y - 2 * delta.x;
		}
	}
	mlx_img_pixel_put(img, to, color);
}
