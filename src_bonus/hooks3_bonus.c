/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:46:15 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/15 10:46:15 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_bonus.h"
#include "screen_points_bonus.h"
#include "zoom_bonus.h"

static float	get_distance(t_vector2int from, t_vector2int to)
{
	return (sqrtf(powf(to.x - from.x, 2) + powf(to.y - from.y, 2)));
}

static void	select_point(t_vector2int mouse_position, t_globals *globals)
{
	int				i;
	int				j;
	float			min_dist;
	float			current_dist;

	min_dist = 30;
	i = 0;
	while (i < globals->map.dimension.y)
	{
		j = 0;
		while (j < globals->map.dimension.x)
		{
			current_dist = get_distance(mouse_position,
					globals->screen_points[i][j].position);
			if (current_dist < min_dist)
			{
				min_dist = current_dist;
				globals->selected_point.y = i;
				globals->selected_point.x = j;
			}
			j++;
		}
		i++;
	}
}

static void	center_position(t_vector2int position, t_globals *globals)
{
	free_screen_points(globals);
	globals->origin_screen_position.x += (int)(WIDTH / 2) - position.x;
	globals->origin_screen_position.y += (int)(HEIGHT / 2) - position.y;
	if (set_screen_points(globals) == EXIT_FAILURE)
	{
		end_loop(globals);
	}
}

int	mouse_hook(int button, int x, int y, t_globals *globals)
{
	if (button == Button1)
		select_point(get_vector2int(x, y), globals);
	else if (button == Button3)
		center_position(get_vector2int(x, y), globals);
	else if (button == Button5)
		zoom_out(globals);
	else if (button == Button4)
		zoom_in(globals);
	return (EXIT_SUCCESS);
}

int	close_window_hook(t_globals *globals)
{
	end_loop(globals);
	return (EXIT_SUCCESS);
}
