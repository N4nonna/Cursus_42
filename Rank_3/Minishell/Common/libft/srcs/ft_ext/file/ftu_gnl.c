/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftu_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:21:30 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/06/05 13:36:58 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*extract_before(char *s, int last);

static char	*joinf_line_buff(char *line, char const *buff, size_t read_c);

static int	search_end(char const *line);

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {0};
	int			ind;
	int			read_c;
	char		*line;
	char		*ret;

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (NULL);
	line = ft_strndup(buff, BUFFER_SIZE + 1);
	ind = search_end(line);
	read_c = 42;
	while (ind <= 0 && read_c != 0)
	{
		read_c = read(fd, buff, BUFFER_SIZE);
		if (line == NULL && read_c == 0)
			return (NULL);
		buff[read_c] = '\0';
		line = joinf_line_buff(line, buff, read_c);
		ind = search_end(line);
		if (read_c == 0 && (line[0] == 0))
			return (free(line), NULL);
	}
	ret = extract_before(line, ft_abs(ind));
	ft_strlcpy(buff, &line[ft_abs(ind)], BUFFER_SIZE);
	return (free(line), ret);
}

char	*get_next_line_mf(int fd)
{
	static char	buff[FD_SETSIZE][BUFFER_SIZE + 1] = {0};
	int			ind;
	int			read_c;
	char		*line;
	char		*ret;

	if (fd < 0 || FD_SETSIZE <= fd || read(fd, buff[fd], 0) < 0)
		return (NULL);
	line = ft_strndup(buff[fd], BUFFER_SIZE + 1);
	ind = search_end(line);
	read_c = 42;
	while (ind <= 0 && read_c != 0)
	{
		read_c = read(fd, buff[fd], BUFFER_SIZE);
		if (line == NULL && read_c == 0)
			return (NULL);
		buff[fd][read_c] = '\0';
		line = joinf_line_buff(line, buff[fd], read_c);
		ind = search_end(line);
		if (read_c == 0 && (line[0] == 0))
			return (free(line), NULL);
	}
	ret = extract_before(line, ft_abs(ind));
	ft_strlcpy(buff[fd], &line[ft_abs(ind)], BUFFER_SIZE);
	return (free(line), ret);
}

static int	search_end(char const *line)
{
	int	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-(i));
}

static char	*joinf_line_buff(char *line, char const *buff, size_t read_c)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = ft_strlen((char *)line) + read_c;
	res = (char *)ft_calloc(i +1, sizeof(char));
	if (res == 0)
		return (NULL);
	j = 0;
	while (line != NULL && line[j])
	{
		res[j] = line[j];
		j++;
	}
	i = 0;
	while (i < read_c)
	{
		res[j + i] = buff[i];
		i++;
	}
	res[j + i] = '\0';
	return (free(line), res);
}

static char	*extract_before(char *s, int last)
{
	char	*dest;

	if (s == NULL || last == 0)
		return (NULL);
	dest = ft_strndup(s, last);
	if (dest == NULL)
		return (free(s), NULL);
	return (dest);
}
