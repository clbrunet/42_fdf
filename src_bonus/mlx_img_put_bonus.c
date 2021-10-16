/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_put_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:23:41 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_put_bonus.h"
#include "ft_bonus.h"

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

t_color	get_color_mix_by_portion(t_color a, t_color b, float b_portion)
{
	t_color	mix;

	mix.bytes.alpha = a.bytes.alpha * (1 - b_portion)
		+ b.bytes.alpha * b_portion;
	mix.bytes.red = a.bytes.red * (1 - b_portion)
		+ b.bytes.red * b_portion;
	mix.bytes.green = a.bytes.green * (1 - b_portion)
		+ b.bytes.green * b_portion;
	mix.bytes.blue = a.bytes.blue * (1 - b_portion)
		+ b.bytes.blue * b_portion;
	return (mix);
}

void	mlx_img_gradient_line_put(t_img *img, t_screen_point from,
		t_screen_point to)
{
	int	delta_x;
	int	delta_y;

	delta_x = ft_abs(to.position.x - from.position.x);
	delta_y = ft_abs(to.position.y - from.position.y);
	if ((from.position.x < 0 && to.position.x < 0)
		|| (from.position.x >= WIDTH && to.position.x >= WIDTH)
		|| (from.position.y < 0 && to.position.y < 0)
		|| (from.position.y >= HEIGHT && to.position.y >= HEIGHT))
		return ;
	if (from.position.y == to.position.y)
		mlx_img_gradient_horizontal_line_put(img, from, to);
	else if (from.position.x == to.position.x)
		mlx_img_gradient_vertical_line_put(img, from, to);
	else if (delta_y > delta_x)
		mlx_img_gradient_rise_line_put(img, from, to);
	else
		mlx_img_gradient_run_line_put(img, from, to);
}
