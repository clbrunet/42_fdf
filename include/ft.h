/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:54:26 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/09 11:54:26 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char const *s);
int		write_str(int const fd, char const *str);
int		ft_abs(int j);
int		ft_max(int a, int b);

#endif
