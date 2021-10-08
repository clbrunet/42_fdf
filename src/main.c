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

void	set_map(t_map *map)
{
	map->dimension.y = 3;
	map->dimension.x = 3;
	map->points = malloc(map->dimension.y * sizeof(t_vector3 *));
	for (int i = 0; i < map->dimension.y; i++)
	{
		map->points[i] = malloc(map->dimension.x * sizeof(t_vector3));
		for (int j = 0; j < map->dimension.x; j++)
		{
			map->points[i][j].x = j * POINT_INTERVAL;
			map->points[i][j].y = 0;
			map->points[i][j].z = (map->dimension.y - 1 - i) * POINT_INTERVAL;
		}
	}
	// map->points[1][1] = 1;
}

int	main(void)
{
	t_globals	globals;

	if (initialize_mlx(&globals) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	set_map(&globals.map);
	globals.camera.position.x = globals.map.dimension.x * POINT_INTERVAL;
	globals.camera.position.y = 2 * POINT_INTERVAL;
	globals.camera.position.z = -POINT_INTERVAL;
	globals.camera.direction.x = -1;
	globals.camera.direction.y = -1;
	globals.camera.direction.z = 1;
	globals.camera.direction = get_vector3_normalize(globals.camera.direction);
	mlx_loop(globals.mlx.ptr);
	for (int i = 0; i < globals.map.dimension.y; i++)
	{
		free(globals.map.points[i]);
	}
	free(globals.map.points);
	mlx_destroy_window(globals.mlx.ptr, globals.mlx.win);
	mlx_destroy_image(globals.mlx.ptr, globals.mlx.img.ptr);
	mlx_destroy_display(globals.mlx.ptr);
	free(globals.mlx.ptr);
	return (EXIT_SUCCESS);
}
