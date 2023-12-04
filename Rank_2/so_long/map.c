/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:35:13 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/04 16:10:25 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_info(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sl_error("ERROR: Map error.(map_info)");
	line = get_next_line(fd);
	if (!line)
		sl_error("ERROR: Map empty.(map_info)");
	tab = ft_split(line, ' ');
	while (tab[env->map_w])
	{
		free(tab[env->map_w]);
		env->map_w++;
	}
	while (line)
	{
		free(line);
		env->map_h++;
		line = get_next_line(fd);
	}
	free(line);
	free(tab);
	close(fd);
}

void	map_check_format_w(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**tab;
	int		x;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line);
		x = 0;
		while (tab[x])
		{
			free(tab[x]);
			x++;
		}
		free(tab);
		if (x < env->map_w || x > env->map_w || x == env->map_h)
			fdf_error("ERROR: Wrong map format.(map_check_format)");
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}

void	map_check_format_wall(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**tab;
	int		w;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	w = 0;
	tab = ft_split(line, ' ');
	free(line);
	while (tab[w])
	{
		if (tab[1] != 1)
			sl_error("ERROR: Map not enclosed with walls.(map_check_format_wall)");
		free(tab);
	}
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line);
		if (tab[1] != 1 || tab[env->map_w] != 1 )
			sl_error("ERROR: Map not enclosed with walls.(map_check_format_wall)");
		free(tab);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}

void	map_parse(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**line_tab;

	fd = open(file, O_RDONLY);
	env->final_tab = malloc(sizeof(int *) * env->map_h); //malloc tab for height
	if (!env->final_tab)
		fdf_error("ERROR: Malloc failed.(map_parse)");
	while (env->y < env->map_h)
	{
		env->final_tab[env->y] = malloc(sizeof(int) * env->map_w); //malloc line for width
		if (!env->final_tab[env->y])
			fdf_error("ERROR: Malloc failed.(map_parse)");
		line = get_next_line(fd);
		line_tab = ft_split(line, ' ');
		free(line);
		env->x = -1;
		while (++env->x < env->map_w) //transform each elements in int
		{
			env->final_tab[env->y][env->x] = ft_atoi(line_tab[env->x]);
			free(line_tab[env->x]);
		}
		env->y++;
		free(line_tab);
	}
}
