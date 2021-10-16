/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:23:34 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"
#include "initialize_mlx_bonus.h"
#include "mlx.h"
#include "map_bonus.h"
#include "tile_bonus.h"
#include "screen_points_bonus.h"
#include "ft_bonus.h"

// @todo remove
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

// @todo remove
static int fail_at = 0;

// @todo remove
void *xmalloc(size_t size)
{
	static int	s = 0;
	s++;
	
	if (s == fail_at)
	{
		return (NULL);
	}
	else
	{
		return (malloc(size));
	}
}

void	end_loop(t_globals *globals)
{
	globals->is_end_loop = 1;
	mlx_loop_end(globals->mlx.ptr);
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

static void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
}

static int	start(t_globals *globals)
{
	if (EXIT_FAILURE == set_map(globals))
	{
		return (EXIT_FAILURE);
	}
	globals->is_end_loop = 0;
	globals->zoom = 1;
	set_tile_dimension(globals);
	set_origin_screen_position(globals);
	if (EXIT_FAILURE == set_screen_points(globals))
	{
		free_map(&globals->map);
		return (EXIT_FAILURE);
	}
	globals->selected_point.x = 0;
	globals->selected_point.y = 0;
	mlx_loop(globals->mlx.ptr);
	free_screen_points(globals);
	free_map(&globals->map);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_globals	globals;
	int			exit_code;

	if (2 != argc)
	{
		write_str(2, "1 argument max required (e.g. `./fdf_bonus map.fdf`).\n");
		return (EXIT_FAILURE);
	}
	else if (set_path(&globals.path, argv[1]) == EXIT_FAILURE
		|| initialize_mlx(&globals) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	exit_code = start(&globals);
	free_mlx(&globals.mlx);
	return (exit_code);
}
