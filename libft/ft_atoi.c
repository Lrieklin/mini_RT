/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:42:27 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/19 23:43:12 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_func(unsigned long res, int minus, int counter)
{
	if (counter > 19)
	{
		if (minus)
			return ((int)(-9223372036854775807L - 1L));
		return ((int)9223372036854775807L);
	}
	if (counter == 19 && res >= 9223372036854775807L && !minus)
		return ((int)9223372036854775807L);
	if (counter == 19 && res >= (unsigned long)9223372036854775807
		+(unsigned long)1L && minus)
		return ((int)(-9223372036854775807L - 1L));
	if (minus)
		return ((int)(res * -1));
	return ((int)res);
}

static const char	*ft_plus_minus(const char *str, int *minus)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*minus = 1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				minus;
	int				counter;

	i = 0;
	res = 0;
	minus = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	str = ft_plus_minus(str, &minus);
	if (!ft_isdigit(str[i]))
		return (0);
	counter = 0;
	while (str[i + counter] >= '0' && str[i + counter] <= '9' )
	{
		res = res * 10 + str[i + counter] - '0';
		counter++;
	}
	return (my_func(res, minus, counter));
}
