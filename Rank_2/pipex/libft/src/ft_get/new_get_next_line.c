/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:30:54 by manon             #+#    #+#             */
/*   Updated: 2024/05/21 13:44:19 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*process_line(char **keep)
{
	char	*line;
	char	*rest;
	int		len;

	len = 0;
	while ((*keep)[len] != '\n' && (*keep)[len] != '\0')
		len++;
	if ((*keep)[len] == '\n')
	{
		line = ft_substr(*keep, 0, len + 1);
		rest = ft_substr(*keep, len + 1, ft_strlen(*keep) - (len + 1));
		free(*keep);
		*keep = rest;
		return (line);
	}
	return (NULL);
}

static char	*read_fd(int fd)
{
	char	*line;
	int		read_b;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	read_b = read(fd, line, BUFFER_SIZE);
	if (read_b <= 0)
	{
		free(line);
		return (NULL);
	}
	line[read_b] = '\0';
	return (line);
}

static char	*gnl(char **keep, int fd)
{
	char	*tmp_keep;
	char	*line;
	char	*ret;

	ret = process_line(keep);
	if (ret)
		return (ret);
	line = read_fd(fd);
	if (!line)
	{
		ret = ft_strdup(*keep);
		free(*keep);
		*keep = NULL;
		if (*ret)
			return (ret);
		free(ret);
		return (NULL);
	}
	tmp_keep = ft_strjoin(*keep, line);
	free(*keep);
	*keep = tmp_keep;
	free(line);
	return (gnl(keep, fd));
}

char	*get_next_line(int fd)
{
	static char	*keep[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(keep[fd]);
		keep[fd] = NULL;
		return (NULL);
	}
	if (!keep[fd])
		keep[fd] = ft_strdup("");
	return (gnl(&keep[fd], fd));
}
