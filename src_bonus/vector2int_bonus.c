/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:07 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/06 17:18:42 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2int_bonus.h"

t_vector2int	get_vector2int(int x, int y)
{
	t_vector2int	vector2int;

	vector2int.x = x;
	vector2int.y = y;
	return (vector2int);
}

float	get_vector2int_magnitude(t_vector2int vector2int)
{
	return (sqrtf(powf(vector2int.x, 2)
			+ powf(vector2int.y, 2)));
}

t_vector2int	get_vector2int_normalize(t_vector2int vector2int)
{
	float	magnitude;

	magnitude = get_vector2int_magnitude(vector2int);
	if (magnitude == 0.0f)
	{
		vector2int.x = 0;
		vector2int.y = 0;
		return (vector2int);
	}
	vector2int.x /= magnitude;
	vector2int.y /= magnitude;
	return (vector2int);
}
