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

#include "hooks_bonus.h"
#include "get_screen_points_bonus.h"

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

void	draw_wires(t_globals *globals, t_screen_point **screen_points)
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
					screen_points[i][j], screen_points[i - 1][j]);
			}
			if (j > 0)
			{
				mlx_img_gradient_line_put(&globals->mlx.img,
					screen_points[i][j], screen_points[i][j - 1]);
			}
			j++;
		}
		i++;
	}
}

int	key_press_hook(int keycode, t_globals *globals)
{
	t_screen_point	**screen_points;

	if (keycode == XK_Escape)
	{
		close_window_hook(globals);
	}
	else if (keycode == XK_r)
	{
		mlx_img_square_put(&globals->mlx.img, get_vector2int(0, 0),
			get_vector2int(WIDTH, HEIGHT), 0);
		screen_points = get_screen_points(globals);
		if (screen_points == NULL)
		{
			write_str(2, "Malloc failed\n");
			return (EXIT_FAILURE);
		}
		draw_wires(globals, screen_points);
		free_screen_points(globals->map.dimension, screen_points);
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
