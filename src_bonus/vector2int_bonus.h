/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2int_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:25 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2INT_BONUS_H
# define VECTOR2INT_BONUS_H

# include <math.h>

typedef struct s_vector2int
{
	int	x;
	int	y;
}	t_vector2int;

t_vector2int	get_vector2int(int x, int y);
float			get_vector2int_magnitude(t_vector2int vector2int);
t_vector2int	get_vector2int_normalize(t_vector2int vector2int);

#endif
