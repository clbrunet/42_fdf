/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:07:45 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/04 12:07:45 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "get_point_screen_positions.h"

int	loop_hook(t_globals *globals)
{
	(void)globals;
	return (EXIT_SUCCESS);
}

int	close_window_hook(t_globals *globals)
{
	mlx_loop_end(globals->mlx.ptr);
	return (EXIT_SUCCESS);
}

int	key_press_hook(int keycode, t_globals *globals)
{
	t_vector2int	**point_screen_positions;

	if (keycode == XK_Escape)
	{
		close_window_hook(globals);
	}
	else if (keycode == XK_r)
	{
		mlx_img_square_put(globals, get_vector2int(0, 0),
			get_vector2int(WIDTH, HEIGHT), 0);
		point_screen_positions = get_point_screen_positions(globals);
		mlx_put_image_to_window(globals->mlx.ptr, globals->mlx.win,
			globals->mlx.img.ptr, 0, 0);
	}
	return (EXIT_SUCCESS);
}

int	key_release_hook(int keycode, t_globals *globals)
{
	(void)keycode;
	(void)globals;
	return (EXIT_SUCCESS);
}
