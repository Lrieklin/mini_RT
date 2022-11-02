/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:57:29 by lrieklin          #+#    #+#             */
/*   Updated: 2021/11/11 16:12:10 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*new_dst;
	const char		*new_src;
	size_t			i;

	new_dst = (char *)dst;
	new_src = (const char *)src;
	i = 0;
	if (new_dst == NULL && new_src == NULL)
		return (NULL);
	if (new_dst == new_src)
		return ((void *)new_dst);
	if (new_dst < new_src)
	{
		return (ft_memcpy (dst, src, len));
	}
	else
	{
		while (len > i)
		{
			new_dst[len - 1] = new_src[len - 1];
			len--;
		}
	}
	return ((void *)new_dst);
}
