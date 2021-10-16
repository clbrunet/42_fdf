/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:25:24 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/14 10:39:36 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translate_bonus.h"
#include "zoom_bonus.h"
#include "screen_points_bonus.h"
#include "tile_bonus.h"

void	translate_left(t_globals *globals)
{
	free_screen_points(globals);
	globals->origin_screen_position.x += TRANSLATION_STEP * globals->zoom;
	if (EXIT_FAILURE == set_screen_points(globals))
	{
		end_loop(globals);
	}
}

void	translate_right(t_globals *globals)
{
	free_screen_points(globals);
	globals->origin_screen_position.x -= TRANSLATION_STEP * globals->zoom;
	if (set_screen_points(globals) == EXIT_FAILURE)
	{
		end_loop(globals);
	}
}

void	translate_down(t_globals *globals)
{
	free_screen_points(globals);
	globals->origin_screen_position.y -= TRANSLATION_STEP * globals->zoom;
	if (set_screen_points(globals) == EXIT_FAILURE)
	{
		end_loop(globals);
	}
}

void	translate_up(t_globals *globals)
{
	free_screen_points(globals);
	globals->origin_screen_position.y += TRANSLATION_STEP * globals->zoom;
	if (set_screen_points(globals) == EXIT_FAILURE)
	{
		end_loop(globals);
	}
}

void	translate_reset(t_globals *globals)
{
	set_origin_screen_position(globals);
	zoom(globals, globals->zoom);
}
