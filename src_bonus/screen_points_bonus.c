/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_points_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:10:12 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen_points_bonus.h"
#include "ft_bonus.h"

static int	allocate_screen_points_rows(
		t_screen_point **screen_points, t_vector2int dimension)
{
	int	i;

	i = 0;
	while (i < dimension.y)
	{
		screen_points[i] = malloc(dimension.x * sizeof(t_screen_point));
		if (screen_points[i] == NULL)
		{
			break ;
		}
		i++;
	}
	if (i < dimension.y)
	{
		while (i >= 0)
		{
			free(screen_points[i]);
			i--;
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	set_screen_points_y_position(t_globals *globals,
		t_screen_point **screen_points, int i, int j)
{
	screen_points[i][j].position.y = globals->origin_screen_position.y;
	screen_points[i][j].position.y += (i + j)
		* (globals->tile_dimension.y * globals->zoom) / 2;
	screen_points[i][j].position.y -= (globals->map.points[i][j].height)
		* (globals->tile_dimension.y * globals->zoom) * TILE_HEIGHT_FACTOR;
}

static void	set_screen_points_values(t_globals *globals,
		t_screen_point **screen_points)
{
	int	i;
	int	j;

	i = 0;
	while (i < globals->map.dimension.y)
	{
		j = 0;
		while (j < globals->map.dimension.x)
		{
			screen_points[i][j].position = globals->origin_screen_position;
			screen_points[i][j].position.x += (j - i)
				* (globals->tile_dimension.x * globals->zoom) / 2;
			set_screen_points_y_position(globals, screen_points, i, j);
			screen_points[i][j].color = globals->map.points[i][j].color;
			j++;
		}
		i++;
	}
}

int	set_screen_points(t_globals *globals)
{
	globals->screen_points = malloc(globals->map.dimension.y
			* sizeof(t_screen_point *));
	if (globals->screen_points == NULL)
	{
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	if (allocate_screen_points_rows(globals->screen_points,
			globals->map.dimension) == EXIT_FAILURE)
	{
		write_str(2, "Malloc failed\n");
		free(globals->screen_points);
		globals->screen_points = NULL;
		return (EXIT_FAILURE);
	}
	set_screen_points_values(globals, globals->screen_points);
	return (EXIT_SUCCESS);
}

void	free_screen_points(t_globals *globals)
{
	int	i;

	if (NULL == globals->screen_points)
	{
		return ;
	}
	i = 0;
	while (i < globals->map.dimension.y)
	{
		free(globals->screen_points[i]);
		i++;
	}
	free(globals->screen_points);
	globals->screen_points = NULL;
}
