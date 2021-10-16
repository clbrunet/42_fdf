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

char	*ft_strcat(char *dest, char const *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*dest)
	{
		dest++;
	}
	ft_strcpy(dest, src);
	return (dest_start);
}

char	*ft_strcpy(char *dest, char const *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}
