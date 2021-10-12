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
#include "mlx_img_put.h"
#include "get_screen_points.h"

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

static void	draw_wires(t_globals *globals, t_screen_point **screen_points)
{
	int	i;
	int	j;

	i = 0;
	while (i < globals->map.dimension.y)
	{
		j = 0;
		while (j < globals->map.dimension.x)
		{
			if (i > 0)
			{
				mlx_img_gradient_line_put(&globals->mlx.img,
					screen_points[i][j], screen_points[i - 1][j]);
			}
			if (j > 0)
			{
				mlx_img_gradient_line_put(&globals->mlx.img,
					screen_points[i][j], screen_points[i][j - 1]);
			}
			j++;
		}
		i++;
	}
}

static int	fill_screen(t_globals *globals)
{
	t_screen_point	**screen_points;

	mlx_img_square_put(&globals->mlx.img, get_vector2int(0, 0),
		get_vector2int(WIDTH, HEIGHT), 0);
	screen_points = get_screen_points(globals);
	if (screen_points == NULL)
	{
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	draw_wires(globals, screen_points);
	free_screen_points(globals->map.dimension, screen_points);
	mlx_put_image_to_window(globals->mlx.ptr, globals->mlx.win,
		globals->mlx.img.ptr, 0, 0);
	return (EXIT_SUCCESS);
}

static void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
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
		if (fill_screen(&globals) == EXIT_SUCCESS)
		{
			mlx_loop(globals.mlx.ptr);
		}
		free_map(&globals.map);
	}
	free_mlx(&globals.mlx);
	return (EXIT_SUCCESS);
}
