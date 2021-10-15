/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:39:55 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include "screen_points_bonus.h"

static int	allocate_rotated_map_points_row(t_point **arr, int row_nb,
		int row_size)
{
	int	i;

	i = 0;
	while (i < row_nb)
	{
		arr[i] = malloc(row_size * sizeof(t_point));
		if (arr[i] == NULL)
		{
			break ;
		}
		i++;
	}
	if (i < row_nb)
	{
		while (i >= 0)
		{
			i--;
			free(arr[i]);
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	fill_left_rotate_map(t_globals *globals,
		t_point **rotated_map_points)
{
	int	i;
	int	j;

	j = globals->map.dimension.x - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < globals->map.dimension.y)
		{
			rotated_map_points[ft_abs(j - (globals->map.dimension.x - 1))][i]
				= globals->map.points[i][j];
			i++;
		}
		j--;
	}
}

int	left_rotate_map(t_globals *globals)
{
	t_point	**rotated_map_points;
	int		tmp;

	tmp = globals->selected_point.x;
	globals->selected_point.y = ft_abs(tmp - (globals->map.dimension.x - 1));
	globals->selected_point.x = globals->selected_point.y;
	rotated_map_points = malloc(globals->map.dimension.x * sizeof(t_point *));
	if (NULL == rotated_map_points
		|| allocate_rotated_map_points_row(rotated_map_points,
			globals->map.dimension.x, globals->map.dimension.y) == EXIT_FAILURE)
	{
		free(rotated_map_points);
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	fill_left_rotate_map(globals, rotated_map_points);
	free_map(&globals->map);
	free_screen_points(globals->map.dimension, globals->screen_points);
	globals->origin_screen_position.x += globals->tile_dimension.y
		* (globals->map.dimension.x - globals->map.dimension.y);
	globals->map.points = rotated_map_points;
	tmp = globals->map.dimension.x;
	globals->map.dimension.x = globals->map.dimension.y;
	globals->map.dimension.y = tmp;
	return (set_screen_points(globals));
}

static void	fill_right_rotate_map(t_globals *globals,
		t_point **rotated_map_points)
{
	int	i;
	int	j;

	j = 0;
	while (j < globals->map.dimension.x)
	{
		i = globals->map.dimension.y - 1;
		while (i >= 0)
		{
			rotated_map_points[j][ft_abs(i - (globals->map.dimension.y - 1))]
				= globals->map.points[i][j];
			i--;
		}
		j++;
	}
}

int	right_rotate_map(t_globals *globals)
{
	t_point	**rotated_map_points;
	int		tmp;

	tmp = globals->selected_point.y;
	globals->selected_point.y = globals->selected_point.x;
	globals->selected_point.x = ft_abs(tmp - (globals->map.dimension.y - 1));
	rotated_map_points = malloc(globals->map.dimension.x * sizeof(t_point *));
	if (NULL == rotated_map_points
		|| allocate_rotated_map_points_row(rotated_map_points,
			globals->map.dimension.x, globals->map.dimension.y) == EXIT_FAILURE)
	{
		free(rotated_map_points);
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	fill_right_rotate_map(globals, rotated_map_points);
	free_map(&globals->map);
	free_screen_points(globals->map.dimension, globals->screen_points);
	globals->origin_screen_position.x += globals->tile_dimension.y
		* (globals->map.dimension.x - globals->map.dimension.y);
	globals->map.points = rotated_map_points;
	tmp = globals->map.dimension.x;
	globals->map.dimension.x = globals->map.dimension.y;
	globals->map.dimension.y = tmp;
	return (set_screen_points(globals));
}
