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

# include "main_bonus.h"

size_t	ft_strlen(char const *s);
size_t	ft_strslen(char const **s);
size_t	ft_str_number_count(char const *s);
void	free_strs(char **s);
int		ft_strcmp(char const *s1, char const *s2);
int		write_str(int const fd, char const *str);
int		ft_abs(int j);
int		ft_max(int a, int b);

#endif
