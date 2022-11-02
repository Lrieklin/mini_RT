/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:28:46 by lrieklin          #+#    #+#             */
/*   Updated: 2021/11/12 00:18:40 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	in_set(char c, char const *set)
{
	int	i;	

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len_s1;
	char	*new_str;

	if (!s1 || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0 && in_set(s1[i], set))
		i++;
	if (s1[i] == '\0')
	{
		new_str = malloc(sizeof(char));
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	len_s1 = ft_strlen((char *)s1);
	while (len_s1 > 0 && in_set(s1[len_s1 - 1], set))
		len_s1--;
	new_str = malloc((len_s1 - i + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, (const char *)(s1 + i), (len_s1 - i) + 1);
	return (new_str);
}
