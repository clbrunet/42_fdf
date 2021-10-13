/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_points_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:11:16 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_POINTS_BONUS_H
# define SCREEN_POINTS_BONUS_H

# include "main_bonus.h"

void	set_screen_points_y_position(t_globals *globals,
			t_screen_point **screen_points, int i, int j);

int		set_screen_points(t_globals *globals);
void	free_screen_points(t_vector2int dimension,
			t_screen_point **arr);

#endif
