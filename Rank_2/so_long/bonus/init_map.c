/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:53:48 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/14 13:11:07 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int ac, char **av, t_data *data)
{
	int	param_len;

	data->map_alloc = false;
	if (ac > 2)
		error("Too many args. Must be 2.(check_args)", data);
	if (ac < 2)
		error("Map file missing.(check_args)", data);
	param_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][param_len - 4], ".ber", 4))
		error("Wrong map file extension. Must be .ber(check_args)", data);
}

void	check_empty_line(char *map, t_data *data)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		error("Invalid map.\
		Musn't beggin with empty line.(check_empty_line)", data);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		error("Invalid map.\
		Musn't end with empty line.(check_empty_line)", data);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			error("Invalid map.\
			Has empty line in middle.(check_empty_line)", data);
		}
		i++;
	}
}

char	*str_append(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	init_map(t_data *data, char *av)
{
	char	*map;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error("Can't open map.(init_map)", data);
	map = ft_strdup("");
	data->map.row = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = str_append(&map, line);
		free(line);
		data->map.row++;
	}
	close(fd);
	check_empty_line(map, data);
	data->map.full = ft_split(map, '\n');
	data->map_alloc = true;
	free(map);
}
