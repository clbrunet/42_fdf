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

void	mlx_img_gradient_horizontal_line_put(t_img *img, t_screen_point from,
			t_screen_point to)
{
	t_vector2int	position;
	int				increment_x;

	increment_x = 1;
	if (to.position.x < from.position.x)
	{
		increment_x = -1;
	}
	position.x = from.position.x;
	position.y = from.position.y;
	while (position.x != to.position.x)
	{
		mlx_img_pixel_put(img, position, 0x00FFFFFF);
		position.x += increment_x;
	}
	mlx_img_pixel_put(img, to.position, 0x00FFFFFF);
}

void	mlx_img_gradient_vertical_line_put(t_img *img, t_screen_point from,
		t_screen_point to)
{
	t_vector2int	position;
	int				increment_y;

	increment_y = 1;
	if (to.position.y < from.position.y)
	{
		increment_y = -1;
	}
	position.x = from.position.x;
	position.y = from.position.y;
	while (position.y != to.position.y)
	{
		mlx_img_pixel_put(img, position, 0x00FFFFFF);
		position.y += increment_y;
	}
	mlx_img_pixel_put(img, to.position, 0x00FFFFFF);
}

static void	mlx_img_line_put_set_increment(t_vector2int *increment,
		t_vector2int from_position, t_vector2int to_position)
{
	if (to_position.x < from_position.x)
	{
		increment->x = -1;
	}
	else
	{
		increment->x = 1;
	}
	if (to_position.y < from_position.y)
	{
		increment->y = -1;
	}
	else
	{
		increment->y = 1;
	}
}

void	mlx_img_gradient_rise_line_put(t_img *img, t_screen_point from,
		t_screen_point to)
{
	t_vector2int	delta;
	t_vector2int	position;
	t_vector2int	increment;
	int				d;

	delta.x = ft_abs(to.position.x - from.position.x);
	delta.y = ft_abs(to.position.y - from.position.y);
	position.x = from.position.x;
	position.y = from.position.y;
	mlx_img_line_put_set_increment(&increment, from.position, to.position);
	d = 2 * delta.x - delta.y;
	while (position.y != to.position.y)
	{
		mlx_img_pixel_put(img, position, 0x00FFFFFF);
		position.y += increment.y;
		if (d < 0)
			d += 2 * delta.x;
		else
		{
			position.x += increment.x;
			d += 2 * delta.x - 2 * delta.y;
		}
	}
	mlx_img_pixel_put(img, to.position, 0x00FFFFFF);
}

void	mlx_img_gradient_run_line_put(t_img *img, t_screen_point from,
		t_screen_point to)
{
	t_vector2int	delta;
	t_vector2int	position;
	t_vector2int	increment;
	int				d;

	delta.x = ft_abs(to.position.x - from.position.x);
	delta.y = ft_abs(to.position.y - from.position.y);
	position.x = from.position.x;
	position.y = from.position.y;
	mlx_img_line_put_set_increment(&increment, from.position, to.position);
	d = 2 * delta.y - delta.x;
	while (position.x != to.position.x)
	{
		mlx_img_pixel_put(img, position, 0x00FFFFFF);
		position.x += increment.x;
		if (d < 0)
			d += 2 * delta.y;
		else
		{
			position.y += increment.y;
			d += 2 * delta.y - 2 * delta.x;
		}
	}
	mlx_img_pixel_put(img, to.position, 0x00FFFFFF);
}
