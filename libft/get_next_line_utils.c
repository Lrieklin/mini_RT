/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:44:14 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/19 23:43:48 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s1 || s1[i] == '\0')
	{
		new_str = malloc(sizeof(char));
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = (char *)malloc((ft_strlen_gnl(s1) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < ft_strlen_gnl(s1))
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*new_func_gnl(char *new_str, char const *s1, char const *s2)
{		
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	free((char *)s1);
	return (new_str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new_str;

	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1)
			* sizeof(char));
	if (new_str)
	{
		return (new_func_gnl(new_str, s1, s2));
	}
	return (NULL);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		else
			i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
