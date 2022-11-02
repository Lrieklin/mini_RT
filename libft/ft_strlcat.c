/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:43:34 by lrieklin          #+#    #+#             */
/*   Updated: 2021/11/11 16:17:25 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	if (dstsize > len_dst)
	{
		while ((i + len_dst + 1) < (dstsize) && src[i])
		{
			dst[i + len_dst] = src[i];
			i++;
		}
		dst[i + len_dst] = '\0';
		return (len_dst + len_src);
	}
	return (dstsize + len_src);
}
