/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:34:19 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/06 18:13:18 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

char	*map_get(int fd)
{
	char	*buff;
	char	*line;
	char	*tmp;
	int		count;

	buff = ft_strdup("");
	line = ft_strdup("");
	count = get_next_line(fd);
	if (count > 0)
	{
		tmp = buff;
		while (count > 0)
		{
			buff = ft_strjoin(buff, line);
			free(line);
			free(tmp);
			line = ft_strdup("");
			count = get_next_line(fd);
			tmp = buff;
		}
		return (buff);
	}
	error("Error\nCan't open map.(map_get)\n");
	return (NULL);
}

char	**map_parse(int fd, t_data *data)
{
	int	i;

	i = 1;
	data->map = ft_split(map_get(fd), '\n');
	check_content(data);
	if (!(check_format_line(data->map)) || !(map_check_square(data->map)))
		map_free(data);
	if (!(check_line(data->map[0], data->content.wall)))
		map_free(data);
	while (data->map[i])
	{
		if (!(check_col(data->map[i], data->content.wall, data)))
			map_free(data);
		else if (!(check_other(data->map[i], data->content)))
			map_free(data);
		i++;
	}
	data->height = i;
	if (!(check_line(data->map[i - 1], data->content.wall)))
		map_free(data);
	return (data->map);
}

char	**map_core(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
		return (error("Error\nWrong map format. Need '.ber'.(map_core)\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = map_parse(fd, data);
		else
			return (error("Error\nCan't read file.(map_core)"));
		if (data->content.count_c == 0 || data->content.count_e != 1
			|| data->content.count_p != 1 || data->map != NULL)
		{
			map_free(data);
			return (error("Error\nInvalid content.(map_core)\n"));
		}
	}
	return (data->map);
}

int	map_check_square(char **map)
{
	int	y;
	int	count_x;

	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y][count_x])
		y++;
	if (count_x == y)
	{
		error("Error\nMap is square.(check_format)\n");
		return (0);
	}
	return (1);
}
