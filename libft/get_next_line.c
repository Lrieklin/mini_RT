/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:30:10 by lrieklin          #+#    #+#             */
/*   Updated: 2022/04/16 21:52:40 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strdup_gnl(const char *s1);
size_t		ft_strlen_gnl(const char *s);

char	*after_n(char *memory_text)
{
	char	*ptr;
	char	*line;

	ptr = ft_strchr_gnl(memory_text, '\n');
	if (ptr)
		ptr++;
	line = ft_strdup_gnl(ptr);
	free(memory_text);
	return (line);
}

char	*read_remainder(char *memory_text)
{
	char	*line;
	long	len_line;
	int		i;

	i = 0;
	len_line = 0;
	if (!memory_text)
		return (NULL);
	if (ft_strchr_gnl(memory_text, '\n') == NULL)
		len_line = ft_strlen_gnl(memory_text);
	else
		len_line = ft_strchr_gnl(memory_text, '\n') - memory_text;
	line = (char *)malloc((len_line + 1) * sizeof(char));
	if (!line)
	{
		free(memory_text);
		return (NULL);
	}
	while (i < len_line + 1)
	{
		line[i] = memory_text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_text(int fd, char *memory_text)
{
	char	*buf;
	int		buf_read_count;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	buf_read_count = 1;
	while (buf_read_count != 0 && ft_strchr_gnl(memory_text, '\n') == NULL)
	{
		buf_read_count = read(fd, buf, BUFFER_SIZE);
		if (buf_read_count < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[buf_read_count] = '\0';
		memory_text = ft_strjoin_gnl(memory_text, buf);
	}
	free(buf);
	return (memory_text);
}

char	*get_next_line(int fd)
{
	static char		*memory_text;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	memory_text = read_text(fd, memory_text);
	if (!(*memory_text))
	{
		free(memory_text);
		memory_text = NULL;
		return (NULL);
	}
	line = read_remainder(memory_text);
	memory_text = after_n(memory_text);
	return (line);
}
