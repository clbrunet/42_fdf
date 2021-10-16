/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:30:10 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/13 15:30:10 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"
#include "hooks_bonus.h"
#include "mlx.h"

void	draw_wires(t_globals *globals)
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
					globals->screen_points[i][j],
					globals->screen_points[i - 1][j]);
			}
			if (j > 0)
			{
				mlx_img_gradient_line_put(&globals->mlx.img,
					globals->screen_points[i][j],
					globals->screen_points[i][j - 1]);
			}
			j++;
		}
		i++;
	}
}

int	put_selected_point_info_error(char *str, char *y, char *x, char *height)
{
	free(str);
	free(y);
	free(x);
	free(height);
	write_str(2, "Malloc failed\n");
	return (EXIT_FAILURE);
}

void	set_selected_point_info(char *str, char *y, char *x, char *height)
{
	*str = '\0';
	ft_strcat(str, "Selected point : y: ");
	ft_strcat(str, y);
	free(y);
	ft_strcat(str, ", x: ");
	ft_strcat(str, x);
	free(x);
	ft_strcat(str, ", height: ");
	ft_strcat(str, height);
	free(height);
}

int	put_selected_point_info(t_globals *globals)
{
	char	*str;
	char	*y;
	char	*x;
	char	*height;

	str = NULL;
	y = ft_itoa(globals->selected_point.y);
	x = ft_itoa(globals->selected_point.x);
	height = ft_itoa(globals->map.points[globals->selected_point.y]
		[globals->selected_point.x].height);
	if (NULL == y || NULL == x || NULL == height)
		return (put_selected_point_info_error(str, y, x, height));
	str = malloc((ft_strlen("Selected point : y: ") + ft_strlen(y)
				+ ft_strlen(", x: ") + ft_strlen(x) + ft_strlen(", height: ")
				+ ft_strlen(height) + 1) * sizeof(char));
	if (NULL == str)
		return (put_selected_point_info_error(str, y, x, height));
	set_selected_point_info(str, y, x, height);
	mlx_string_put(globals->mlx.ptr, globals->mlx.win, 0, 10, 0x00FFFFFF, str);
	free(str);
	return (EXIT_SUCCESS);
}

int	loop_hook(t_globals *globals)
{
	static int	s = 0;

	if (globals->is_end_loop)
	{
		return (EXIT_SUCCESS);
	}
	mlx_img_square_put(&globals->mlx.img, get_vector2int(0, 0),
		get_vector2int(WIDTH, HEIGHT), 0);
	if (s == 0)
	{
		s++;
	}
	draw_wires(globals);
	mlx_put_image_to_window(globals->mlx.ptr, globals->mlx.win,
		globals->mlx.img.ptr, 0, 0);
	if (EXIT_FAILURE == put_selected_point_info(globals))
	{
		end_loop(globals);
	}
	return (EXIT_SUCCESS);
}
