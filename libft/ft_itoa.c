/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:45:28 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/21 10:23:42 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*null_func(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*my_func(char *str, int count, int znak, int n)
{
	str[count] = '\0';
	while (n != 0)
	{
		str[--count] = (char)((n % 10) * znak + '0');
		n = n / 10;
	}
	count--;
	if (znak < 0)
		str[count] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	int		num;
	int		znak;
	char	*str;

	count = 0;
	num = n;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	znak = 1;
	if (n < 0)
		znak = -1;
	count = count + (n <= 0);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (str);
	if (n == 0)
		return (null_func(str));
	return (my_func(str, count, znak, n));
}
