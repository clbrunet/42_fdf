/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:19:13 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/13 10:19:13 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

int	pop_color(char *line, int *i)
{
	char	digit_value;
	long	n;

	*i += 3;
	n = 0;
	while (('0' <= line[*i] && line[*i] <= '9')
		|| ('a' <= line[*i] && line[*i] <= 'f')
		|| ('A' <= line[*i] && line[*i] <= 'F'))
	{
		if ('0' <= line[*i] && line[*i] <= '9')
			digit_value = line[*i] - '0';
		else if ('a' <= line[*i] && line[*i] <= 'f')
			digit_value = line[*i] - 'a' + 10;
		else
			digit_value = line[*i] - 'A' + 10;
		n = n * 16 + digit_value;
		(*i)++;
	}
	return (n);
}
