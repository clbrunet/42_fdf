/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_put2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:16:41 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_img_put_bonus.h"
#include "ft_bonus.h"

void	mlx_img_gradient_horizontal_line_put(t_img *img, t_screen_point from,
			t_screen_point to)
{
	t_vector2int	position;
	int				increment_x;
	float			to_color_portion;
	float			to_color_portion_increment;

	to_color_portion = 0;
	to_color_portion_increment = 1.0 / ft_abs(to.position.x - from.position.x);
	increment_x = 1;
	if (to.position.x < from.position.x)
	{
		increment_x = -1;
	}
	position.x = from.position.x;
	position.y = from.position.y;
	while (position.x != to.position.x)
	{
		mlx_img_pixel_put(img, position, get_color_mix_by_portion(from.color,
				to.color, to_color_portion).full);
		to_color_portion += to_color_portion_increment;
		position.x += increment_x;
	}
	mlx_img_pixel_put(img, to.position, to.color.full);
}

void	mlx_img_gradient_vertical_line_put(t_img *img, t_screen_point from,
		t_screen_point to)
{
	t_vector2int	position;
	int				increment_y;
	float			to_color_portion;
	float			to_color_portion_increment;

	to_color_portion = 0;
	to_color_portion_increment = 1.0 / ft_abs(to.position.y - from.position.y);
	increment_y = 1;
	if (to.position.y < from.position.y)
	{
		increment_y = -1;
	}
	position.x = from.position.x;
	position.y = from.position.y;
	while (position.y != to.position.y)
	{
		mlx_img_pixel_put(img, position, get_color_mix_by_portion(from.color,
				to.color, to_color_portion).full);
		to_color_portion += to_color_portion_increment;
		position.y += increment_y;
	}
	mlx_img_pixel_put(img, to.position, to.color.full);
}
