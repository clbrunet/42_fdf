/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:30:55 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	failed_malloc(void *to_free)
{
	free(to_free);
	return (-2);
}

int	end(int bytes_read, int len, char **line, char *buf)
{
	int	i;

	if (bytes_read == -1)
		return (-1);
	else if (!len)
	{
		*line = malloc(sizeof(char));
		if (*line == NULL)
			return (-2);
		line[0][0] = '\0';
		return (0);
	}
	i = 0;
	while (i < BUFFER_SIZE + 1)
		buf[i++] = 0;
	return (0);
}
