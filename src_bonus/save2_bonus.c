/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:40:41 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/17 18:40:41 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save_bonus.h"
#include "ft_bonus.h"

static int	get_save_file_content_length(t_point_strings **points_strings,
		t_globals *globals)
{
	int	length;
	int	i;
	int	j;

	length = 0;
	i = 0;
	while (i < globals->map.dimension.y)
	{
		j = 0;
		while (j < globals->map.dimension.x)
		{
			length += ft_strlen(points_strings[i][j].height)
				+ 3 + ft_strlen(points_strings[i][j].color) + 1;
			j++;
		}
		i++;
	}
	return (length);
}

static void	fill_save_file_content(char *content,
		t_point_strings **points_strings, t_map *map)
{
	int	i;
	int	j;

	*content = '\0';
	i = 0;
	while (i < map->dimension.y)
	{
		j = 0;
		while (j < map->dimension.x)
		{
			ft_strcat(content, points_strings[i][j].height);
			ft_strcat(content, ",0x");
			ft_strcat(content, points_strings[i][j].color);
			j++;
			if (j < map->dimension.x)
			{
				ft_strcat(content, " ");
			}
		}
		ft_strcat(content, "\n");
		i++;
	}
}

int	write_save_file(t_point_strings **points_strings, t_globals *globals)
{
	int		content_length;
	char	*content;
	char	fd;

	content_length = get_save_file_content_length(points_strings, globals);
	content = malloc((content_length + 1) * sizeof(char));
	if (NULL == content)
	{
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	fill_save_file_content(content, points_strings, &globals->map);
	fd = open(globals->path, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH);
	if (-1 == fd || write(fd, content, content_length) == -1)
	{
		write_str(2, "Syscall open or write failed during save\n");
		free(content);
		if (fd != -1)
			close(fd);
		return (EXIT_FAILURE);
	}
	free(content);
	close(fd);
	return (EXIT_SUCCESS);
}
