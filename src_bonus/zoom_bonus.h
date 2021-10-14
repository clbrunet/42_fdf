/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:30:59 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/14 10:40:17 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOOM_BONUS_H
# define ZOOM_BONUS_H

# include "main_bonus.h"

void	zoom_reset(t_globals *globals);
void	zoom_in(t_globals *globals);
void	zoom_out(t_globals *globals);
void	zoom(t_globals *globals, float zoom);

#endif
