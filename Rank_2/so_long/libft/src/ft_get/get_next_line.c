/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:10:09 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/10 18:08:40 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *keep, char *buff)
{
	char	*tmp;

	tmp = str_join(keep, buff);
	free(keep);
	return (tmp);
}

static char	*get_before_newline(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	res = calloc_bzero(i + 2, sizeof(char));
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		res[i++] = '\n';
	return (res);
}

static char	*get_after_newline(char *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	res = calloc_bzero((ft_strlen(s) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (s[i])
		res[j++] = s[i++];
	free(s);
	return (res);
}

static char	*ft_read_line(int fd, char *keep)
{
	char	*buff;
	int		i;

	if (!keep)
		keep = ft_calloc(1, 1);
	buff = calloc_bzero(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[i] = '\0';
		keep = ft_free(keep, buff);
		if (str_chr(buff, '\n'))
			break ;
	}
	free(buff);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0) < 0)
		return (NULL);
	keep[fd] = ft_read_line(fd, keep[fd]);
	if (!keep[fd])
		return (NULL);
	line = get_before_newline(keep[fd]);
	keep[fd] = get_after_newline(keep[fd]);
	return (line);
}
