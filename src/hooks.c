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

void	draw_wires(t_globals *globals, t_vector2int **point_screen_positions)
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
				mlx_img_line_put(&globals->mlx.img,
					point_screen_positions[i][j],
					point_screen_positions[i - 1][j], 0x00FFFFFF);
			}
			if (j > 0)
			{
				mlx_img_line_put(&globals->mlx.img,
					point_screen_positions[i][j],
					point_screen_positions[i][j - 1], 0x00FFFFFF);
			}
			j++;
		}
		i++;
	}
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
		mlx_img_square_put(&globals->mlx.img, get_vector2int(0, 0),
			get_vector2int(WIDTH, HEIGHT), 0);
		point_screen_positions = get_point_screen_positions(globals);
		if (point_screen_positions == NULL)
		{
			write_str(2, "Malloc failed\n");
			return (EXIT_FAILURE);
		}
		draw_wires(globals, point_screen_positions);
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
