/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:19:46 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/12 16:41:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include "get_file_lines_bonus.h"
#include "get_next_line_bonus.h"

static int	pop_number(char *line, int *i)
{
	long	n;
	int		sign;

	sign = 1;
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	n = 0;
	while ('0' <= line[*i] && line[*i] <= '9')
	{
		n = n * 10 + line[*i] - '0';
		(*i)++;
	}
	return (n * sign);
}

static void	set_map_points(t_map *map, char **lines)
{
	int	i;
	int	j;
	int	line_iterator;

	i = 0;
	while (i < map->dimension.y)
	{
		j = 0;
		line_iterator = 0;
		while (j < map->dimension.x)
		{
			map->points[i][j].height = pop_number(lines[i], &line_iterator);
			if (',' == lines[i][line_iterator])
			{
				map->points[i][j].color.full = pop_color(lines[i],
						&line_iterator);
			}
			else
			{
				map->points[i][j].color.full = 0x00FFFFFF;
			}
			j++;
		}
		i++;
	}
}

static int	allocate_map_rows(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->dimension.y)
	{
		map->points[i] = malloc(map->dimension.x * sizeof(t_point));
		if (map->points[i] == NULL)
		{
			break ;
		}
		i++;
	}
	if (i < map->dimension.y)
	{
		while (i >= 0)
		{
			i--;
			free(map->points[i]);
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	set_map(t_globals *globals)
{
	char	**lines;

	lines = get_file_lines(globals->path);
	if (lines == NULL)
		return (EXIT_FAILURE);
	globals->map.dimension.y = ft_strslen((char const **)lines);
	globals->map.dimension.x = ft_str_word_count(*lines);
	globals->map.points = malloc(globals->map.dimension.y * sizeof(t_point *));
	if (globals->map.points == NULL)
	{
		free_strs(lines);
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	if (allocate_map_rows(&globals->map) == EXIT_FAILURE)
	{
		free_strs(lines);
		free(globals->map.points);
		write_str(2, "Malloc failed\n");
		return (EXIT_FAILURE);
	}
	set_map_points(&globals->map, lines);
	free_strs(lines);
	return (EXIT_SUCCESS);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->dimension.y)
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
}
