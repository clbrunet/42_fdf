/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:40:38 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
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

size_t	ft_str_word_count(char const *s)
{
	size_t	count;

	count = 0;
	while ('\0' != *s)
	{
		if (' ' != *s)
		{
			count++;
			while (' ' != *s && '\0' != *s)
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

char	*ft_strchr(char const *s, int c)
{
	char	c_c;

	c_c = (char)c;
	while (*s && *s != c_c)
	{
		s++;
	}
	if (*s == c_c)
	{
		return ((char *)s);
	}
	return ((char *) NULL);
}

char	*ft_strcpy(char *dst, const char *src)
{
	char const	*dst_bp;

	if (!dst || !src)
		return (0);
	dst_bp = dst;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return ((char *)dst_bp);
}
