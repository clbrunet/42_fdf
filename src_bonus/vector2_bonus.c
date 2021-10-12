/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:07 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/06 20:16:00 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2_bonus.h"

t_vector2	get_vector2(float x, float y)
{
	t_vector2	vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

float	get_vector2_magnitude(t_vector2 vector2)
{
	return (sqrtf(powf(vector2.x, 2)
			+ powf(vector2.y, 2)));
}

t_vector2	get_vector2_normalize(t_vector2 vector2)
{
	float	magnitude;

	magnitude = get_vector2_magnitude(vector2);
	if (magnitude == 0.0f)
	{
		vector2.x = 0;
		vector2.y = 0;
		return (vector2);
	}
	vector2.x /= magnitude;
	vector2.y /= magnitude;
	return (vector2);
}
