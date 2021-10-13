/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:21:40 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "mlx.h"

# include "ft_bonus.h"
# include "vector2int_bonus.h"
# include "vector2_bonus.h"
# include "vector3_bonus.h"

# define WIDTH 1080
# define HEIGHT 720

# define TILE_HEIGHT_FACTOR 0.4

# define RESET		"\x1B[0m"
# define BOLD		"\x1B[1m"
# define BLACK		"\x1B[30m"
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_argb
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	alpha;
}	t_argb;

typedef union u_color
{
	unsigned int	full;
	t_argb			bytes;
}	t_color;

typedef struct s_point
{
	int		height;
	t_color	color;
}	t_point;

typedef struct s_screen_point
{
	t_vector2int	position;
	t_color			color;
}	t_screen_point;

typedef struct s_map
{
	t_point			**points;
	t_vector2int	dimension;
}	t_map;

typedef struct s_globals
{
	t_mlx			mlx;
	char			*path;
	t_map			map;
	t_screen_point	**screen_points;
	t_vector2int	tile_dimension;
	t_vector2int	origin_screen_position;
}	t_globals;

// to remove
void print_vector2int(char const *name, t_vector2int v2i);

#endif
