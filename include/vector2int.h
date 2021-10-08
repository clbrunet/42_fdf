/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:25 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/06 17:16:45 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2INT_H
# define VECTOR2INT_H

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
