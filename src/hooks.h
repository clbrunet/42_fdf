/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:08:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/04 12:08:37 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <X11/X.h>
# include "main.h"

int	loop_hook(t_globals *globals);
int	close_window_hook(t_globals *globals);
int	key_press_hook(int keycode, t_globals *globals);
int	key_release_hook(int keycode, t_globals *globals);

#endif
