/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:21:40 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/04 11:21:40 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "mlx.h"

# include "ft.h"
# include "vector2int.h"
# include "vector2.h"
# include "vector3.h"

# define WIDTH 1080
# define HEIGHT 720

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

typedef struct s_map
{
	int				**point_heights;
	t_vector2int	dimension;
}	t_map;

typedef struct s_globals
{
	t_mlx			mlx;
	t_map			map;
	t_vector2int	tile_dimension;
	t_vector2int	origin_screen_position;
}	t_globals;

// to remove
void print_vector2int(char const *name, t_vector2int v2i);

#endif
