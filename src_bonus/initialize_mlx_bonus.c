/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:04:26 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_mlx_bonus.h"
#include "hooks_bonus.h"
#include "ft_bonus.h"

static int	initialize_mlx_win(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "fdf_bonus");
	if (mlx->win == NULL)
	{
		write_str(2, "Window creation failed\n");
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	initialize_mlx_img(t_mlx *mlx)
{
	mlx->img.ptr = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	if (mlx->img.ptr == NULL)
	{
		write_str(2, "Image creation failed\n");
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		return (EXIT_FAILURE);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	return (EXIT_SUCCESS);
}

static int	initialize_mlx_hooks(t_globals *globals)
{
	mlx_loop_hook(globals->mlx.ptr, &loop_hook, globals);
	mlx_mouse_hook(globals->mlx.win, &mouse_hook, globals);
	mlx_hook(globals->mlx.win, KeyPress, KeyPressMask, &key_press_hook,
		globals);
	mlx_hook(globals->mlx.win, ClientMessage, StructureNotifyMask,
		&close_window_hook, globals);
	return (EXIT_SUCCESS);
}

int	initialize_mlx(t_globals *globals)
{
	globals->mlx.ptr = mlx_init();
	if (globals->mlx.ptr == NULL)
	{
		write_str(2, "Connection between software and display failed\n");
		return (EXIT_FAILURE);
	}
	if (initialize_mlx_win(&globals->mlx) == EXIT_FAILURE
		|| initialize_mlx_img(&globals->mlx) == EXIT_FAILURE
		|| initialize_mlx_hooks(globals) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
