/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:05:50 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/11 17:53:34 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle_bonus.h"

float	degrees_to_radians(float degrees)
{
	return (degrees * M_PI / 180);
}

float	radians_to_degrees(float radians)
{
	return (radians * 180 / M_PI);
}
