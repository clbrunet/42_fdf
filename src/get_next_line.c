/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:31:21 by clbrunet          #+#    #+#             */
/*   Updated: 2020/12/16 05:54:46 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strdup_start_of_line(char *buf, char **line, int len)
{
	int		i;
	char	*buf_bp;

	*line = malloc((len + 1) * sizeof(char));
	if (*line == NULL)
		return (-2);
	buf_bp = buf;
	i = 0;
	while (i < len)
		line[0][i++] = *(buf++);
	line[0][i] = 0;
	if (!*buf)
		return (i);
	ft_strcpy(buf_bp, buf + 1);
	return (0);
}

static int	ft_strdup_continuation_of_line(char *buf, char **line,
		int prev_len, int len)
{
	char	*tmp;
	int		i;
	char	*buf_bp;

	tmp = malloc((prev_len + 1) * sizeof(char));
	if (tmp == NULL)
		return (failed_malloc(*line));
	ft_strcpy(tmp, *line);
	free(*line);
	*line = malloc((prev_len + len + 1) * sizeof(char));
	if (*line == NULL)
		return (failed_malloc(tmp));
	i = 0;
	while (i < prev_len)
		line[0][i++] = *(tmp++);
	free(tmp - i);
	buf_bp = buf;
	while (i < prev_len + len)
		line[0][i++] = *(buf++);
	line[0][i] = 0;
	if (!*buf)
		return (i);
	ft_strcpy(buf_bp, buf + 1);
	return (0);
}

static int	ft_strdup_line(char *buf, char **line, int prev_len)
{
	char	*s;

	s = buf;
	while (*s && *s != '\n')
		s++;
	if (!prev_len)
		return (ft_strdup_start_of_line(buf, line, s - buf));
	return (ft_strdup_continuation_of_line(buf, line, prev_len, s - buf));
}

int	call_read(int *bytes_read, int fd, char bufs[259][BUFFER_SIZE + 1])
{
	*bytes_read = read(fd, bufs[fd], BUFFER_SIZE);
	return (*bytes_read);
}

int	get_next_line(int fd, char **line)
{
	static char	bufs[259][BUFFER_SIZE + 1] = {{0}};
	int			bytes_read;
	int			len;
	int			have_to_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line || fd > 258)
		return (-1);
	len = 0;
	have_to_read = !(bufs[fd][0]);
	while (!have_to_read || call_read(&bytes_read, fd, bufs) > 0)
	{
		if (have_to_read)
			bufs[fd][bytes_read] = 0;
		len = ft_strdup_line(bufs[fd], line, len);
		if (len <= 0)
		{
			if (len == -1)
				return (-1);
			else if (len == -2)
				return (-2);
			return (1);
		}
		have_to_read = 1;
	}
	return (end(bytes_read, len, line, bufs[fd]));
}
