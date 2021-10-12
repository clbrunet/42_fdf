/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:22:05 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/10 09:22:05 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile.h"

static float	get_map_screen_height_highest(t_map *map)
{
	int		i;
	int		j;
	float	highest;
	float	current;

	highest = map->points[0][0].height / 2.5;
	i = 0;
	while (i < map->dimension.y)
	{
		j = 0;
		while (j < map->dimension.x)
		{
			current = i * -0.5 + j * -0.5;
			current += map->points[i][j].height / 2.5;
			if (current > highest)
			{
				highest = current;
			}
			j++;
		}
		i++;
	}
	return (highest);
}

static float	get_map_screen_height_lowest(t_map *map)
{
	int		i;
	int		j;
	float	lowest;
	float	current;

	lowest = map->points[0][0].height / 2.5;
	i = 0;
	while (i < map->dimension.y)
	{
		j = 0;
		while (j < map->dimension.x)
		{
			current = i * -0.5 + j * -0.5;
			current += map->points[i][j].height / 2.5;
			if (current < lowest)
			{
				lowest = current;
			}
			j++;
		}
		i++;
	}
	return (lowest);
}

static float	get_map_screen_height(t_map *map)
{
	return (get_map_screen_height_highest(map)
		- get_map_screen_height_lowest(map));
}

void	set_tile_dimension(t_globals *globals)
{
	int		size_x;
	float	size_y;
	int		quotient_x;
	int		quotient_y;

	size_x = globals->map.dimension.y + globals->map.dimension.x - 2;
	size_y = get_map_screen_height(&globals->map);
	if (size_x == 0)
	{
		globals->tile_dimension.x = 0;
		globals->tile_dimension.y = 0;
		return ;
	}
	quotient_x = (WIDTH - (int)(WIDTH / 20)) / size_x;
	quotient_y = (HEIGHT - (int)(HEIGHT / 20)) / size_y;
	if (quotient_x < quotient_y)
	{
		globals->tile_dimension.x = quotient_x * 2;
		globals->tile_dimension.y = quotient_x;
	}
	else
	{
		globals->tile_dimension.x = quotient_y * 2;
		globals->tile_dimension.y = quotient_y;
	}
}

void	set_origin_screen_position(t_globals *globals)
{
	int		size_x;
	float	size_y;
	float	highest;

	size_x = globals->map.dimension.y + globals->map.dimension.x - 2;
	size_y = get_map_screen_height(&globals->map);
	highest = get_map_screen_height_highest(&globals->map);
	globals->origin_screen_position.x = (int)(WIDTH / 2)
		- (size_x * globals->tile_dimension.y) / 2
		+ (globals->map.dimension.y - 1) * globals->tile_dimension.y;
	globals->origin_screen_position.y = (int)(HEIGHT / 2)
		- (size_y * globals->tile_dimension.y) / 2
		+ (highest * globals->tile_dimension.y);
}
