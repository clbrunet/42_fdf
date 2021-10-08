/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:07 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/05 14:36:07 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	get_vector3(float x, float y, float z)
{
	t_vector3	vector3;

	vector3.x = x;
	vector3.y = y;
	vector3.z = z;
	return (vector3);
}

float	get_vector3_magnitude(t_vector3 vector3)
{
	return (sqrtf(powf(vector3.x, 2)
			+ powf(vector3.y, 2)
			+ powf(vector3.z, 2)));
}

t_vector3	get_vector3_normalize(t_vector3 vector3)
{
	float	magnitude;

	magnitude = get_vector3_magnitude(vector3);
	if (magnitude == 0.0f)
	{
		vector3.x = 0;
		vector3.y = 0;
		vector3.z = 0;
		return (vector3);
	}
	vector3.x /= magnitude;
	vector3.y /= magnitude;
	vector3.z /= magnitude;
	return (vector3);
}
