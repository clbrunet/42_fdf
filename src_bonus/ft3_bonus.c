/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft3_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:13:19 by clbrunet          #+#    #+#             */
/*   Updated: 2021/10/15 12:13:19 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*s_s;
	unsigned char	uc_c;

	s_s = (char *)s;
	uc_c = (unsigned char)c;
	while (n--)
	{
		*s_s = uc_c;
		s_s++;
	}
	return (s);
}

unsigned int	get_number_length_base(unsigned long n, int len,
		unsigned int base)
{
	if (n > base - 1)
	{
		return (get_number_length_base(n / base, len + 1, base));
	}
	return (len);
}

static void	ft_itoa_conv(char *a, long n)
{
	if (n > 9)
	{
		ft_itoa_conv(a - 1, n / 10);
	}
	*a = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char			*a;
	long			l_n;
	unsigned int	len;
	int				is_negative;

	l_n = (long)n;
	is_negative = 0;
	if (l_n < 0)
	{
		l_n *= -1;
		is_negative = 1;
	}
	len = get_number_length_base(l_n, is_negative + 1, 10);
	a = malloc((len + 1) * sizeof(char));
	if (NULL == a)
		return ((char *) NULL);
	a[len] = 0;
	if (is_negative)
		*a = '-';
	ft_itoa_conv(a + len - 1, l_n);
	return (a);
}
