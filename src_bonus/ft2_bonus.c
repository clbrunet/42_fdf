/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:40:38 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/10 20:40:38 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

size_t	ft_strslen(char const **s)
{
	char const	**start;

	start = s;
	while (*s != NULL)
	{
		s++;
	}
	return (s - start);
}

void	free_strs(char **s)
{
	char	**start;

	if (s == NULL)
		return ;
	start = s;
	while (*s != NULL)
	{
		free(*s);
		s++;
	}
	free(start);
}

size_t	ft_str_number_count(char const *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if ('0' <= *s && *s <= '9')
		{
			count++;
			while ('0' <= *s && *s <= '9')
			{
				s++;
			}
		}
		else
		{
			s++;
		}
	}
	return (count);
}
