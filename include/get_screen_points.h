/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_points.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:11:16 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/10 10:40:11 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_SCREEN_POINTS_H
# define GET_SCREEN_POINTS_H

# include "main.h"

t_screen_point	**get_screen_points(t_globals *globals);
void			free_screen_points(t_vector2int dimension,
					t_screen_point **arr);

#endif
