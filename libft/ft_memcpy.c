/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:57:23 by lrieklin          #+#    #+#             */
/*   Updated: 2021/11/12 18:06:03 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*new_dst;
	const char	*new_src;

	i = 0;
	new_dst = (char *) dst;
	new_src = (char *) src;
	if (new_dst == NULL && new_src == NULL)
		return (NULL);
	while (i < n)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (dst);
}
