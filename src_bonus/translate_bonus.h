/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:27:05 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/14 10:40:23 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATE_BONUS_H
# define TRANSLATE_BONUS_H

# include "main_bonus.h"

void	translate_left(t_globals *globals);
void	translate_right(t_globals *globals);
void	translate_down(t_globals *globals);
void	translate_up(t_globals *globals);
void	translate_reset(t_globals *globals);

#endif
