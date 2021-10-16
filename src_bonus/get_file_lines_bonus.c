/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_lines_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:36:55 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_file_lines_bonus.h"
#include "get_next_line_bonus.h"
#include "ft_bonus.h"

static int	strsadd_back(char ***strs_ptr, unsigned int len, char *new)
{
	char			**tmp;
	unsigned int	j;

	tmp = malloc(sizeof(char *) * (len + 1));
	if (tmp == NULL)
	{
		return (EXIT_FAILURE);
	}
	j = 0;
	while (j < len - 1)
	{
		tmp[j] = (*strs_ptr)[j];
		j++;
	}
	tmp[j++] = new;
	tmp[j] = NULL;
	free(*strs_ptr);
	*strs_ptr = tmp;
	return (EXIT_SUCCESS);
}

static void	*open_error(char const *path)
{
	write_str(2, "Cannot open `");
	write_str(2, path);
	write_str(2, "`.\n");
	return (NULL);
}

static void	*gnl_error(int ret, char **lines, int fd)
{
	free_strs(lines);
	if (ret == -1)
	{
		write_str(2, "Read failed.\n");
	}
	else if (ret == -2)
	{
		write_str(2, "Malloc failed\n");
	}
	close(fd);
	return (NULL);
}

static void	*strsadd_back_error(char *line, char **lines, int fd)
{
	free(line);
	free_strs(lines);
	close(fd);
	write_str(2, "Malloc failed\n");
	return (NULL);
}

char	**get_file_lines(char const *path)
{
	char	**lines;
	int		fd;
	int		ret;
	char	*line;
	int		i;

	lines = NULL;
	i = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (open_error(path));
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		if (strsadd_back(&lines, i, line) == EXIT_FAILURE)
			return (strsadd_back_error(line, lines, fd));
		i++;
		ret = get_next_line(fd, &line);
	}
	if (ret < 0)
		return (gnl_error(ret, lines, fd));
	free(line);
	close(fd);
	return (lines);
}
