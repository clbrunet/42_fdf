/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:07:45 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/04 12:07:45 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "vector2int.h"
#include "angle.h"
#include <math.h>

int	loop_hook(t_globals *globals)
{
	(void)globals;
	return (EXIT_SUCCESS);
}

int	close_window_hook(t_globals *globals)
{
	mlx_loop_end(globals->mlx.ptr);
	return (EXIT_SUCCESS);
}

float		get_opposite_side(t_vector3 camera_direction,
		t_vector3 point_direction)
{
	float	camera_magnitude;
	float	point_magnitude;
	float	radian_angle;

	camera_magnitude = get_vector3_magnitude(camera_direction);
	point_magnitude = get_vector3_magnitude(point_direction);

	float dot_product = camera_direction.x * point_direction.x
				+ camera_direction.y * point_direction.y
				+ camera_direction.z * point_direction.z;
	float cos = dot_product / camera_magnitude / point_magnitude;
	if (cos > 1)
	{
		cos = 1;
	}
	else if (cos < -1)
	{
		cos = -1;
	}
	radian_angle = acosf(cos);

	float cross_product = camera_direction.x * point_direction.y
		- camera_direction.x * point_direction.z
		- camera_direction.y * point_direction.x
		- camera_direction.y * point_direction.z
		- camera_direction.z * point_direction.x
		- camera_direction.z * point_direction.y;
	float sin = cross_product / camera_magnitude / point_magnitude;
	if (sin > 0)
	{
		radian_angle *= -1;
	}
	printf(BLUE"radian_angle : %f\n"RESET, (radian_angle));
	printf(GREEN"degree_angle : %f\n"RESET, radians_to_degrees(radian_angle));
	printf("by sin : %f\n", radians_to_degrees(asinf(sin)));
	if (point_magnitude < camera_magnitude)
	{
		printf(RED"EXPLOSION\n"RESET);
	}
	float opposite = sinf(radian_angle) / point_magnitude;
	return (opposite * 15000);
}

t_vector2int	get_world_point_screen_position(t_vector3 camera_direction,
		t_vector3 point_direction)
{
	t_vector2int	position;

	printf("\ncamera direction for plotter : (%f, %f, %f)\n", camera_direction.x, camera_direction.z, camera_direction.y);
	printf("\npoint direction for plotter : (%f, %f, %f)\n", point_direction.x, point_direction.z, point_direction.y);
	printf(RED "X\n" RESET);
	position.x = -get_opposite_side(
			get_vector3(camera_direction.x, 0, camera_direction.z),
			get_vector3(point_direction.x, 0, point_direction.z)
			);
	printf(RED "Y\n" RESET);
	position.y = -get_opposite_side(
			get_vector3(0, camera_direction.y, camera_direction.z),
			get_vector3(0, point_direction.y, camera_direction.z)
			);
	printf("position :\n\tx: %d, %d\n\ty: %d, %d\n", position.x,
			position.x + WIDTH / 2, position.y, position.y + HEIGHT / 2);
	position.x += WIDTH / 2;
	position.y += (int)(HEIGHT / 2);
	printf("\n");
	return (position);
}

void	test_point(t_globals *globals, t_vector3 point, int i, int j)
{
	t_vector3 direction;
	t_vector2int position;

	if ((i != 1 || j != 0) && (i != 0 || j != 1)) return;
	// printf("[%d][%d]\n", i, j);
	printf("[%d][%d] : %f %f %f\n", i, j, point.x, point.y, point.z);
	direction.x = point.x - globals->camera.position.x;
	direction.y = point.y - globals->camera.position.y;
	direction.z = point.z - globals->camera.position.z;
	if (0 && i == 0 && j == 0)
	{
		printf("[%d][%d] : %f %f %f\n", i, j, point.x, point.y, point.z);
		printf("\nVector :\nx: %f\ny: %f\nz: %f\n", direction.x, direction.y, direction.z);
	}
	// direction = get_vector3_normalize(direction);
	int magnitude = get_vector3_magnitude(direction);
	t_vector3 camera_direction_magnitude;
	camera_direction_magnitude.x = globals->camera.direction.x * magnitude;
	camera_direction_magnitude.y = globals->camera.direction.y * magnitude;
	camera_direction_magnitude.z = globals->camera.direction.z * magnitude;
	// position = get_world_point_screen_position(globals->camera.direction, direction);
	position = get_world_point_screen_position(globals->camera.direction, direction); //toremove

	// position.x = (int)(WIDTH / 2) + (direction.x - camera_direction_magnitude.x);
	// position.x += (direction.z - camera_direction_magnitude.z);
	// position.y = (int)(HEIGHT / 2) - (direction.y - camera_direction_magnitude.y);
	// position.y += (direction.z / 2 - camera_direction_magnitude.z);
	//
	// int mult = 800;
	// position.x = (int)(WIDTH / 2) + (direction.x - globals->camera.direction.x) * mult;
	// position.x += (direction.z - globals->camera.direction.z) * mult;
	// position.y = (int)(HEIGHT / 2) - (direction.y - globals->camera.direction.y) * mult;
	// position.y -= (direction.z - globals->camera.direction.z) * mult;
	if (0 && i == 0 && j == 1)
	{
		printf("\npoint :\nx: %f\ny: %f\nz: %f\n", point.x, point.y, point.z);
		printf("\ndirection :\nx: %f\ny: %f\nz: %f\n", direction.x, direction.y, direction.z);
		printf("\ndirection for plotter : (%f, %f, %f)\n", direction.x, direction.z, direction.y);
		printf("\ncamera direction :\nx: %f\ny: %f\nz: %f\n", camera_direction_magnitude.x, camera_direction_magnitude.y, camera_direction_magnitude.z);
		printf("\ncamera direction for plotter : (%f, %f, %f)\n", camera_direction_magnitude.x, camera_direction_magnitude.z, camera_direction_magnitude.y);
		printf("\noffset x: %f\n", (direction.x - globals->camera.direction.x));
		printf("offset y: %f\n", (direction.y - globals->camera.direction.y));
		printf("offset z: %f\n", (direction.z - globals->camera.direction.z));
		printf("\nscreen position : x: %d, y: %d\n", position.x, position.y);
		printf("\nfrom center : x: %d, y: %d\n",
				position.x - (int)(WIDTH / 2), position.y - (int)(HEIGHT / 2));
	}

	unsigned int color = 0x00FFFFFF;
	// color = 0;
	// if (i == 0 && j == 0) color = 0x00FF0000;
	// else if (i == 0 && j == 1) color = 0x00A00000;
	// else if (i == 0 && j == 2) color = 0x00FFFFFF;
	// if (i == 1 && j == 0) color = 0x0000FF00;
	// if (i == 1 && j == 1) color = 0x0000A000;
	// if (i == 1 && j == 2) color = 0x00008000;
	// if (i == 2 && j == 0) color = 0x00FFFFFF;
	// if (i == 2 && j == 1) color = 0x00808080;
	// if (i == 2 && j == 2) color = 0x00404040;
	// if (i == 0 && j == 1) color = 0x00FF0000;
	mlx_img_square_put(globals, position, get_vector2int(5, 5), color);
}

void	test(t_globals *globals)
{
	mlx_img_square_put(globals, get_vector2int(0, 0), get_vector2int(WIDTH, HEIGHT), 0);
	printf("\ncamera.position :\nx: %f\ny: %f\nz: %f\n", globals->camera.position.x, globals->camera.position.y, globals->camera.position.z);
	printf("\ncamera.direction :\nx: %f\ny: %f\nz: %f\n", globals->camera.direction.x, globals->camera.direction.y, globals->camera.direction.z);
	for (int i = 0; i < globals->map.dimension.y; i++)
	{
		for (int j = 0; j < globals->map.dimension.x; j++)
		{
			test_point(globals, globals->map.points[i][j], i, j);
		}
	}
	printf("\n");
	mlx_put_image_to_window(globals->mlx.ptr, globals->mlx.win,
			globals->mlx.img.ptr, 0, 0);
}

int	key_press_hook(int keycode, t_globals *globals)
{
	if (keycode == XK_Escape)
	{
		close_window_hook(globals);
	}
	else if (keycode == XK_w)
	{
		globals->camera.position.x += globals->camera.direction.x;
		globals->camera.position.y += globals->camera.direction.y;
		globals->camera.position.z += globals->camera.direction.z;
		printf("\ncamera.position :\nx: %f\ny: %f\nz: %f\n", globals->camera.position.x, globals->camera.position.y, globals->camera.position.z);
	}
	else if (keycode == XK_s)
	{
		globals->camera.position.x -= globals->camera.direction.x;
		globals->camera.position.y -= globals->camera.direction.y;
		globals->camera.position.z -= globals->camera.direction.z;
	}
	else if (keycode == XK_r)
	{
		test(globals);
	}
	return (EXIT_SUCCESS);
}

int	key_release_hook(int keycode, t_globals *globals)
{
	(void)keycode;
	(void)globals;
	return (EXIT_SUCCESS);
}
