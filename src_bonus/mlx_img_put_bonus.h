/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_put_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:24:19 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_PUT_BONUS_H
# define MLX_IMG_PUT_BONUS_H

# include "main_bonus.h"

typedef struct s_gradient
{
	float	portion;
	float	portion_increment;
}	t_gradient;

void	mlx_img_pixel_put(t_img *img, t_vector2int position,
			unsigned int color);

void	mlx_img_square_put(t_img *img, t_vector2int top_left_position,
			t_vector2int dimension, unsigned int color);

t_color	get_color_mix_by_portion(t_color a, t_color b, float b_portion);

void	mlx_img_gradient_horizontal_line_put(t_img *img, t_screen_point from,
			t_screen_point to);
void	mlx_img_gradient_vertical_line_put(t_img *img, t_screen_point from,
			t_screen_point to);
void	mlx_img_gradient_rise_line_put(t_img *img, t_screen_point from,
			t_screen_point to);
void	mlx_img_gradient_run_line_put(t_img *img, t_screen_point from,
			t_screen_point to);
void	mlx_img_gradient_line_put(t_img *img, t_screen_point from,
			t_screen_point to);

#endif
