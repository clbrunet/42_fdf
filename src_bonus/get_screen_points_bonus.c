/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_points.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:10:12 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/10 10:40:59 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_screen_points_bonus.h"

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

static void	set_screen_points(t_globals *globals,
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
				* globals->tile_dimension.x / 2;
			screen_points[i][j].position.y += (i + j)
				* globals->tile_dimension.y / 2;
			screen_points[i][j].position.y -= (globals->map.points[i][j].height)
				* globals->tile_dimension.y / 2.5;
			j++;
		}
		i++;
	}
}

t_screen_point	**get_screen_points(t_globals *globals)
{
	t_screen_point	**screen_points;

	screen_points = malloc(globals->map.dimension.y
			* sizeof(t_screen_point *));
	if (screen_points == NULL)
	{
		return (NULL);
	}
	if (allocate_screen_points_rows(screen_points,
			globals->map.dimension) == EXIT_FAILURE)
	{
		free(screen_points);
		return (NULL);
	}
	set_screen_points(globals, screen_points);
	return (screen_points);
}

void	free_screen_points(t_vector2int dimension, t_screen_point **arr)
{
	int	i;

	i = 0;
	while (i < dimension.y)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
