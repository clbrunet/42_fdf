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

void	mlx_img_pixel_put(t_globals *globals, t_vector2int position,
			unsigned int color);
void	mlx_img_square_put(t_globals *globals, t_vector2int position,
			t_vector2int dimension, unsigned int color);

#endif
