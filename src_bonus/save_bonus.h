/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 07:45:31 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/17 07:45:31 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_BONUS_H
# define SAVE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "main_bonus.h"

int	save(t_globals *globals);

#endif
