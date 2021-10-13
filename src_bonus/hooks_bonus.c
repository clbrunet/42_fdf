/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:07:45 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_bonus.h"
#include "map_bonus.h"
#include "screen_points_bonus.h"

static void	draw_wires(t_globals *globals)
{
	int	i;
	int	j;

	i = 0;
	while (i < globals->map.dimension.y)
	{
		j = 0;
		while (j < globals->map.dimension.x)
		{
			if (i > 0)
			{
				mlx_img_gradient_line_put(&globals->mlx.img,
					globals->screen_points[i][j],
					globals->screen_points[i - 1][j]);
			}
			if (j > 0)
			{
				mlx_img_gradient_line_put(&globals->mlx.img,
					globals->screen_points[i][j],
					globals->screen_points[i][j - 1]);
			}
			j++;
		}
		i++;
	}
}

int	loop_hook(t_globals *globals)
{
	static int	s = 0;

	mlx_img_square_put(&globals->mlx.img, get_vector2int(0, 0),
		get_vector2int(WIDTH, HEIGHT), 0);
	if (s == 0)
	{
		s++;
	}
	draw_wires(globals);
	mlx_put_image_to_window(globals->mlx.ptr, globals->mlx.win,
		globals->mlx.img.ptr, 0, 0);
	return (EXIT_SUCCESS);
}

int	close_window_hook(t_globals *globals)
{
	mlx_loop_end(globals->mlx.ptr);
	return (EXIT_SUCCESS);
}

int	key_press_hook(int keycode, t_globals *globals)
{
	if (XK_Escape == keycode)
	{
		close_window_hook(globals);
	}
	else if (XK_Up == keycode)
	{
		globals->map.points[0][1].height++;
		set_screen_points_y_position(globals, globals->screen_points, 0, 1);
	}
	else if (XK_Down == keycode)
	{
		globals->map.points[0][1].height--;
		set_screen_points_y_position(globals, globals->screen_points, 0, 1);
	}
	else if (XK_Left == keycode)
	{
		left_rotate_map(globals);
	}
	else if (XK_Right == keycode)
	{
		right_rotate_map(globals);
	}
	return (EXIT_SUCCESS);
}

int	key_release_hook(int keycode, t_globals *globals)
{
	(void)keycode;
	(void)globals;
	return (EXIT_SUCCESS);
}
