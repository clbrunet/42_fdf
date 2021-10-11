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

static int	set_path(char **path_ptr, char *arg)
{
	char	*start;

	start = arg;
	while (*arg != '\0')
	{
		arg++;
	}
	if (arg - start < 4 || ft_strcmp(arg - 4, ".fdf") != 0)
	{
		write_str(2, "The argument must be in format : `*.fdf`.\n");
		return (EXIT_FAILURE);
	}
	*path_ptr = start;
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_globals	globals;

	if (argc != 2)
	{
		write_str(2, "1 argument max required (e.g. `./fdf map/42.fdf`).\n");
		return (EXIT_FAILURE);
	}
	if (set_path(&globals.path, argv[1]) == EXIT_FAILURE
		|| initialize_mlx(&globals) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (set_map(&globals) == EXIT_SUCCESS)
	{
		set_tile_dimension(&globals);
		set_origin_screen_position(&globals);
		mlx_loop(globals.mlx.ptr);
		free_map(&globals.map);
	}
	mlx_destroy_window(globals.mlx.ptr, globals.mlx.win);
	mlx_destroy_image(globals.mlx.ptr, globals.mlx.img.ptr);
	mlx_destroy_display(globals.mlx.ptr);
	free(globals.mlx.ptr);
	return (EXIT_SUCCESS);
}
