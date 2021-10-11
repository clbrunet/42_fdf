/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_put.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:24:19 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/04 16:24:19 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_PUT_H
# define MLX_IMG_PUT_H

# include "main.h"

void	mlx_img_pixel_put(t_img *img, t_vector2int position,
			unsigned int color);

void	mlx_img_square_put(t_img *img, t_vector2int top_left_position,
			t_vector2int dimension, unsigned int color);

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
