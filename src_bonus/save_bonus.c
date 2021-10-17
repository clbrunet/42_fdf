/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 07:44:50 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/17 07:44:50 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save_bonus.h"
#include "ft_bonus.h"

static int	allocate_points_strings(t_point_strings ***points_strings, t_map *map)
{
	int	i;

	*points_strings = malloc(map->dimension.y * sizeof(t_point_strings *));
	if (NULL == *points_strings)
		return (EXIT_FAILURE);
	i = 0;
	while (i < map->dimension.y)
	{
		(*points_strings)[i] = malloc(map->dimension.x * sizeof(t_point_strings));
		if (NULL == (*points_strings)[i])
			break;
		ft_memset((*points_strings)[i], 0, map->dimension.x * sizeof(t_point_strings));
		i++;
	}
	if (i < map->dimension.y)
	{
		while (i >= 0)
		{
			free((*points_strings)[i]);
			i--;
		}
		free(*points_strings);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	fill_points_strings(t_point_strings **points_strings, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->dimension.y)
	{
		j = 0;
		while (j < map->dimension.x)
		{
			points_strings[i][j].height = ft_itoa(map->points[i][j].height);
			points_strings[i][j].color = ft_hextoa(map->points[i][j].color.full);
			if (NULL == points_strings[i][j].height
				|| NULL == points_strings[i][j].color)
			{
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	free_points_strings(t_point_strings **points_strings, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->dimension.y)
	{
		j = 0;
		while (j < map->dimension.x)
		{
			free(points_strings[i][j].height);
			free(points_strings[i][j].color);
			j++;
		}
		free(points_strings[i]);
		i++;
	}
	free(points_strings);
}

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

static int	write_save_file(t_point_strings **points_strings,
		t_globals *globals)
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
	if (-1 == fd || -1 == write(fd, content, content_length))
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

int	save(t_globals *globals)
{
	t_point_strings	**points_strings;

	if (EXIT_FAILURE == allocate_points_strings(&points_strings, &globals->map))
	{
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	if (EXIT_FAILURE == fill_points_strings(points_strings, &globals->map))
	{
		free_points_strings(points_strings, &globals->map);
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	if (EXIT_SUCCESS == write_save_file(points_strings, globals))
	{
		write_str(1, "Map saved\n");
	}
	free_points_strings(points_strings, &globals->map);
	return (EXIT_SUCCESS);
}
