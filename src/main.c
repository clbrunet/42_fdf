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
#include "map.h"
#include "tile.h"

// to remove
void print_vector2int(char const *name, t_vector2int v2i)
{
	if (name)
	{
		printf("%s :\n", name);
	}
	else
	{
		printf("vector2int :\n");
	}
	printf("\tx : %d\n", v2i.x);
	printf("\ty : %d\n", v2i.y);
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
