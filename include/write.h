/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:24:17 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/04 11:24:17 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_H
# define WRITE_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"

size_t	ft_strlen(char const *s);
int		write_str(int const fd, char const *str);

#endif
