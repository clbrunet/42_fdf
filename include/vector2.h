/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:25 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/06 20:16:22 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector2_H
# define vector2_H

# include <math.h>

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;


t_vector2	get_vector2(float x, float y);
float			get_vector2_magnitude(t_vector2 vector2);
t_vector2	get_vector2_normalize(t_vector2 vector2);

#endif
