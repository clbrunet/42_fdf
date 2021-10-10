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
	size_t	length;

	length = 0;
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
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
