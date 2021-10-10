/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_screen_positions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:10:12 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/08 16:10:12 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_point_screen_positions.h"

static int	allocate_point_screen_positions_rows(
		t_vector2int **point_screen_positions, t_vector2int dimension)
{
	int	i;

	i = 0;
	while (i < dimension.y)
	{
		point_screen_positions[i] = malloc(dimension.x * sizeof(t_vector2int));
		if (point_screen_positions[i] == NULL)
		{
			break ;
		}
		i++;
	}
	if (i < dimension.y)
	{
		while (i >= 0)
		{
			free(point_screen_positions[i]);
			i--;
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	set_point_screen_positions(t_globals *globals,
		t_vector2int **point_screen_positions)
{
	int	i;
	int	j;

	i = 0;
	while (i < globals->map.dimension.y)
	{
		j = 0;
		while (j < globals->map.dimension.x)
		{
			point_screen_positions[i][j] = globals->origin_screen_position;
			point_screen_positions[i][j].x += (j - i)
				* globals->tile_dimension.x / 2;
			point_screen_positions[i][j].y += (i + j)
				* globals->tile_dimension.y / 2;
			point_screen_positions[i][j].y -= (globals->map.point_heights[i][j])
				* globals->tile_dimension.y / 2.5;
			j++;
		}
		i++;
	}
}

t_vector2int	**get_point_screen_positions(t_globals *globals)
{
	t_vector2int	**point_screen_positions;

	point_screen_positions = malloc(globals->map.dimension.y
			* sizeof(t_vector2int*));
	if (point_screen_positions == NULL)
	{
		return (NULL);
	}
	if (allocate_point_screen_positions_rows(point_screen_positions,
			globals->map.dimension) == EXIT_FAILURE)
	{
		free(point_screen_positions);
		return (NULL);
	}
	set_point_screen_positions(globals, point_screen_positions);
	return (point_screen_positions);
}
