/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft4_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:38:48 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/17 10:38:48 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	ft_hextoa_conv(char *a, unsigned int n)
{
	if (n > 15)
	{
		ft_hextoa_conv(a - 1, n / 16);
	}
	if (n % 16 > 9)
	{
		*a = n % 16 - 10 + 'a';
	}
	else
	{
		*a = n % 16 + '0';
	}
}

char	*ft_hextoa(unsigned int n)
{
	char			*a;
	unsigned int	len;

	len = get_number_length_base(n, 1, 16);
	a = malloc((len + 1) * sizeof(char));
	if (NULL == a)
		return ((char *) NULL);
	a[len] = 0;
	ft_hextoa_conv(a + len - 1, n);
	return (a);
}
