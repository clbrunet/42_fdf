/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:25 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/05 14:36:25 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <math.h>

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

t_vector3	get_vector3(float x, float y, float z);
float		get_vector3_magnitude(t_vector3 vector3);
t_vector3	get_vector3_normalize(t_vector3 vector3);

#endif
