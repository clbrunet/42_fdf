/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:54:26 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# include "main_bonus.h"

size_t			ft_strlen(char const *s);
size_t			ft_strslen(char const **s);
size_t			ft_str_word_count(char const *s);
void			free_strs(char **s);
int				ft_strcmp(char const *s1, char const *s2);
char			*ft_strcat(char *dest, char const *src);
char			*ft_strcpy(char *dest, char const *src);
int				write_str(int const fd, char const *str);
int				ft_abs(int j);
int				ft_max(int a, int b);
void			*ft_memset(void *s, int c, size_t n);
unsigned int	get_number_length_base(unsigned long n, int len,
					unsigned int base);
char			*ft_itoa(int n);
char			*ft_hextoa(unsigned int n);

#endif
