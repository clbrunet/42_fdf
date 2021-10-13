/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:25 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_BONUS_H
# define VECTOR2_BONUS_H

# include <math.h>

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

t_vector2	get_vector2(float x, float y);
float		get_vector2_magnitude(t_vector2 vector2);
t_vector2	get_vector2_normalize(t_vector2 vector2);

#endif
