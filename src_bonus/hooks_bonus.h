/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:08:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

# include <X11/X.h>
# include "main_bonus.h"
# include "mlx_img_put_bonus.h"

int	loop_hook(t_globals *globals);
int	close_window_hook(t_globals *globals);
int	key_press_hook(int keycode, t_globals *globals);
int	key_release_hook(int keycode, t_globals *globals);

#endif
