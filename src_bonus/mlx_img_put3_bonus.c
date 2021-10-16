/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_put3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:41:26 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/13 11:41:26 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_put_bonus.h"
#include "ft_bonus.h"

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

static void	mlx_img_gradient_rise_line_put_next_position(int *d,
		t_vector2int *position, t_vector2int increment, t_vector2int delta)
{
	position->y += increment.y;
	if (*d < 0)
	{
		*d += 2 * delta.x;
	}
	else
	{
		position->x += increment.x;
		*d += 2 * delta.x - 2 * delta.y;
	}
}

void	mlx_img_gradient_rise_line_put(t_img *img, t_screen_point from,
		t_screen_point to)
{
	t_vector2int	delta;
	t_vector2int	position;
	t_vector2int	increment;
	int				d;
	t_gradient		gradient;

	gradient.portion = 0;
	gradient.portion_increment = 1.0 / ft_abs(to.position.y - from.position.y);
	delta.x = ft_abs(to.position.x - from.position.x);
	delta.y = ft_abs(to.position.y - from.position.y);
	position.x = from.position.x;
	position.y = from.position.y;
	mlx_img_line_put_set_increment(&increment, from.position, to.position);
	d = 2 * delta.x - delta.y;
	while (position.y != to.position.y)
	{
		mlx_img_pixel_put(img, position, get_color_mix_by_portion(from.color,
				to.color, gradient.portion).full);
		gradient.portion += gradient.portion_increment;
		mlx_img_gradient_rise_line_put_next_position(&d, &position,
			increment, delta);
	}
	mlx_img_pixel_put(img, to.position, to.color.full);
}

static void	mlx_img_gradient_run_line_put_next_position(int *d,
		t_vector2int *position, t_vector2int increment, t_vector2int delta)
{
	position->x += increment.x;
	if (*d < 0)
	{
		*d += 2 * delta.y;
	}
	else
	{
		position->y += increment.y;
		*d += 2 * delta.y - 2 * delta.x;
	}
}

void	mlx_img_gradient_run_line_put(t_img *img, t_screen_point from,
		t_screen_point to)
{
	t_vector2int	delta;
	t_vector2int	position;
	t_vector2int	increment;
	int				d;
	t_gradient		gradient;

	gradient.portion = 0;
	gradient.portion_increment = 1.0 / ft_abs(to.position.x - from.position.x);
	delta.x = ft_abs(to.position.x - from.position.x);
	delta.y = ft_abs(to.position.y - from.position.y);
	position.x = from.position.x;
	position.y = from.position.y;
	mlx_img_line_put_set_increment(&increment, from.position, to.position);
	d = 2 * delta.y - delta.x;
	while (position.x != to.position.x)
	{
		mlx_img_pixel_put(img, position, get_color_mix_by_portion(from.color,
				to.color, gradient.portion).full);
		gradient.portion += gradient.portion_increment;
		mlx_img_gradient_run_line_put_next_position(&d, &position,
			increment, delta);
	}
	mlx_img_pixel_put(img, to.position, to.color.full);
}
