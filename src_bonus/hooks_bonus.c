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
#include "tile_bonus.h"
#include "screen_points_bonus.h"
#include "translate_bonus.h"
#include "zoom_bonus.h"

static int	key_press_hook_zoom(int keycode, t_globals *globals)
{
	if (XK_0 == keycode)
	{
		zoom_reset(globals);
	}
	else if (XK_minus == keycode)
	{
		zoom_out(globals);
	}
	else if (XK_equal == keycode)
	{
		zoom_in(globals);
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	key_press_hook_translate(int keycode, t_globals *globals)
{
	if (XK_h == keycode)
	{
		translate_left(globals);
	}
	else if (XK_l == keycode)
	{
		translate_right(globals);
	}
	else if (XK_j == keycode)
	{
		translate_down(globals);
	}
	else if (XK_k == keycode)
	{
		translate_up(globals);
	}
	else if (XK_r == keycode)
	{
		translate_reset(globals);
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	key_press_hook_rotate_map(int keycode, t_globals *globals)
{
	if (XK_Left == keycode)
	{
		if (left_rotate_map(globals) == EXIT_FAILURE)
		{
			mlx_loop_end(globals->mlx.ptr);
		}
	}
	else if (XK_Right == keycode)
	{
		if (right_rotate_map(globals) == EXIT_FAILURE)
		{
			mlx_loop_end(globals->mlx.ptr);
		}
	}
	else
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	key_press_hook(int keycode, t_globals *globals)
{
	if (XK_Escape == keycode)
		mlx_loop_end(globals->mlx.ptr);
	else if (XK_Up == keycode)
	{
		globals->map.points[globals->selected_point.y]
		[globals->selected_point.x].height++;
		set_screen_points_y_position(globals, globals->screen_points,
			globals->selected_point.y, globals->selected_point.x);
	}
	else if (XK_Down == keycode)
	{
		globals->map.points[globals->selected_point.y]
		[globals->selected_point.x].height--;
		set_screen_points_y_position(globals, globals->screen_points,
			globals->selected_point.y, globals->selected_point.x);
	}
	else if (EXIT_SUCCESS == key_press_hook_rotate_map(keycode, globals)
		|| EXIT_SUCCESS == key_press_hook_translate(keycode, globals)
		|| EXIT_SUCCESS == key_press_hook_zoom(keycode, globals))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	key_release_hook(int keycode, t_globals *globals)
{
	(void)keycode;
	(void)globals;
	return (EXIT_SUCCESS);
}
