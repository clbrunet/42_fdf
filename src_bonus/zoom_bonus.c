/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:31:27 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/14 10:39:47 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoom_bonus.h"
#include "main_bonus.h"
#include "tile_bonus.h"
#include "screen_points_bonus.h"

void	zoom_reset(t_globals *globals)
{
	free_screen_points(globals);
	set_tile_dimension(globals);
	globals->zoom = 1;
	if (EXIT_FAILURE == set_screen_points(globals))
	{
		end_loop(globals);
	}
}

void	zoom_in(t_globals *globals)
{
	free_screen_points(globals);
	globals->origin_screen_position.x = (int)(WIDTH / 2)
		+ (globals->zoom + 0.1)
		* (globals->origin_screen_position.x - (int)(WIDTH / 2))
		/ globals->zoom;
	globals->origin_screen_position.y = (int)(HEIGHT / 2)
		+ (globals->zoom + 0.1)
		* (globals->origin_screen_position.y - (int)(HEIGHT / 2))
		/ globals->zoom;
	globals->zoom += 0.1;
	if (EXIT_FAILURE == set_screen_points(globals))
	{
		end_loop(globals);
	}
}

void	zoom_out(t_globals *globals)
{
	if (globals->zoom < 0.15)
	{
		return ;
	}
	free_screen_points(globals);
	globals->origin_screen_position.x = (int)(WIDTH / 2)
		+ (globals->zoom - 0.1)
		* (globals->origin_screen_position.x - (int)(WIDTH / 2))
		/ globals->zoom;
	globals->origin_screen_position.y = (int)(HEIGHT / 2)
		+ (globals->zoom - 0.1)
		* (globals->origin_screen_position.y - (int)(HEIGHT / 2))
		/ globals->zoom;
	globals->zoom -= 0.1;
	if (EXIT_FAILURE == set_screen_points(globals))
	{
		end_loop(globals);
	}
}

void	zoom(t_globals *globals, float zoom)
{
	if (zoom < 0.099999)
	{
		return ;
	}
	free_screen_points(globals);
	globals->origin_screen_position.x = (int)(WIDTH / 2) + zoom
		* (globals->origin_screen_position.x - (int)(WIDTH / 2));
	globals->origin_screen_position.y = (int)(HEIGHT / 2) + zoom
		* (globals->origin_screen_position.y - (int)(HEIGHT / 2));
	globals->zoom = zoom;
	if (EXIT_FAILURE == set_screen_points(globals))
	{
		end_loop(globals);
	}
}
