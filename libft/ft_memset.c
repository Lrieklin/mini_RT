/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:34:05 by lrieklin          #+#    #+#             */
/*   Updated: 2022/01/19 15:58:38 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*new_b;

	new_b = (char *)b;
	i = 0;
	while (i < len)
	{
		new_b[i] = (unsigned char)c;
		i++;
	}
	return ((void *)new_b);
}
