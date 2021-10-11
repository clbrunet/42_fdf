/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:53:57 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/09 11:53:57 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	ft_strlen(char const *s)
{
	char const	*start;

	start = s;
	while (*s != '\0')
	{
		s++;
	}
	return (s - start);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	unsigned char const	*u_s1;
	unsigned char const	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (*u_s1 && *u_s1 == *u_s2)
	{
		u_s1++;
		u_s2++;
	}
	return ((int)(*u_s1 - *u_s2));
}

int	write_str(int const fd, char const *str)
{
	return (write(fd, str, ft_strlen(str)));
}

int	ft_abs(int j)
{
	if (j < 0)
	{
		return (-j);
	}
	return (j);
}

int	ft_max(int a, int b)
{
	if (a < b)
	{
		return (b);
	}
	return (a);
}
