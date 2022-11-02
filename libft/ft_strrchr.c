/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:23:09 by lrieklin          #+#    #+#             */
/*   Updated: 2022/01/19 15:59:29 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = (int)ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + n));
	n--;
	while (n >= 0)
	{
		if (s[n] == (char) c)
			return ((char *)(s + n));
		n--;
	}
	return (NULL);
}
