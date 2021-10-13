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

static void	key_press_hook4(int keycode, t_globals *globals)
{
	if (XK_j == keycode)
	{
		free_screen_points(globals->map.dimension, globals->screen_points);
		globals->origin_screen_position.y -= TRANSLATION_STEP;
		if (set_screen_points(globals) == EXIT_FAILURE)
		{
			close_window_hook(globals);
		}
	}
	else if (XK_k == keycode)
	{
		free_screen_points(globals->map.dimension, globals->screen_points);
		globals->origin_screen_position.y += TRANSLATION_STEP;
		if (set_screen_points(globals) == EXIT_FAILURE)
		{
			close_window_hook(globals);
		}
	}
}

static void	key_press_hook3(int keycode, t_globals *globals)
{
	if (XK_h == keycode)
	{
		free_screen_points(globals->map.dimension, globals->screen_points);
		globals->origin_screen_position.x += TRANSLATION_STEP;
		if (set_screen_points(globals) == EXIT_FAILURE)
		{
			close_window_hook(globals);
		}
	}
	else if (XK_l == keycode)
	{
		free_screen_points(globals->map.dimension, globals->screen_points);
		globals->origin_screen_position.x -= TRANSLATION_STEP;
		if (set_screen_points(globals) == EXIT_FAILURE)
		{
			close_window_hook(globals);
		}
	}
	else
	{
		return (key_press_hook4(keycode, globals));
	}
}

static void	key_press_hook2(int keycode, t_globals *globals)
{
	if (XK_Left == keycode)
	{
		if (left_rotate_map(globals) == EXIT_FAILURE)
		{
			close_window_hook(globals);
		}
	}
	else if (XK_Right == keycode)
	{
		if (right_rotate_map(globals) == EXIT_FAILURE)
		{
			close_window_hook(globals);
		}
	}
	else
	{
		return (key_press_hook3(keycode, globals));
	}
}

int	key_press_hook(int keycode, t_globals *globals)
{
	if (XK_d == keycode)
	{
	}
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
	else
	{
		key_press_hook2(keycode, globals);
	}
	return (EXIT_SUCCESS);
}

int	key_release_hook(int keycode, t_globals *globals)
{
	(void)keycode;
	(void)globals;
	return (EXIT_SUCCESS);
}
