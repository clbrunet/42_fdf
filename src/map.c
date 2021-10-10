/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:19:46 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/10 09:19:46 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	set_map_point_heights(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->dimension.y)
	{
		j = 0;
		while (j < map->dimension.x)
		{
			map->point_heights[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int	allocate_map_rows(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->dimension.y)
	{
		map->point_heights[i] = malloc(map->dimension.x * sizeof(int));
		if (map->point_heights[i] == NULL)
		{
			break ;
		}
		i++;
	}
	if (i < map->dimension.y)
	{
		while (i >= 0)
		{
			free(map->point_heights[i]);
			i--;
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	set_map(t_map *map)
{
	map->dimension.y = 3;
	map->dimension.x = 3;
	map->point_heights = malloc(map->dimension.y * sizeof(int *));
	if (map->point_heights == NULL)
	{
		return (EXIT_FAILURE);
	}
	if (allocate_map_rows(map) == EXIT_FAILURE)
	{
		free(map->point_heights);
		return (EXIT_FAILURE);
	}
	set_map_point_heights(map);
	map->point_heights[0][0] = 5;
	map->point_heights[1][1] = 0;
	map->point_heights[0][2] = 5;
	map->point_heights[2][0] = 5;
	map->point_heights[2][2] = 5;
	return (EXIT_SUCCESS);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->dimension.y)
	{
		free(map->point_heights[i]);
		i++;
	}
	free(map->point_heights);
}
