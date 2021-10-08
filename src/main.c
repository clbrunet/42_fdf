/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:23:34 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/04 10:23:34 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "initialize_mlx.h"
#include "mlx.h"

void	set_map_point_heights(t_map *map)
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

int	allocate_map_rows(t_map *map)
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
	map->point_heights[1][1] = 1;
	return (EXIT_SUCCESS);
}

void	set_tile_dimension(t_globals *globals)
{
	int		size_x;
	float	size_y;
	int		quotient_x;
	int		quotient_y;

	size_x = globals->map.dimension.y + globals->map.dimension.x - 2;
	size_y = (float)size_x / 2;
	quotient_x = (WIDTH - (int)(WIDTH / 5)) / size_x;
	quotient_y = (HEIGHT - (int)(HEIGHT / 5)) / size_y;
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
	float	size_y;

	size_y = (float)(globals->map.dimension.y + globals->map.dimension.x - 2)
		/ 2;
	globals->origin_screen_position.x = (int)(WIDTH / 2);
	globals->origin_screen_position.y = (int)(HEIGHT / 2)
		- (size_y * globals->tile_dimension.y) / 2;
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

int	main(void)
{
	t_globals	globals;

	if (initialize_mlx(&globals) == EXIT_FAILURE
		|| set_map(&globals.map) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	set_tile_dimension(&globals);
	set_origin_screen_position(&globals);
	mlx_loop(globals.mlx.ptr);
	free_map(&globals.map);
	mlx_destroy_window(globals.mlx.ptr, globals.mlx.win);
	mlx_destroy_image(globals.mlx.ptr, globals.mlx.img.ptr);
	mlx_destroy_display(globals.mlx.ptr);
	free(globals.mlx.ptr);
	return (EXIT_SUCCESS);
}
