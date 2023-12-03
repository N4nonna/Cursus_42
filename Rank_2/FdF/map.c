/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:35:13 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/03 16:00:10 by mescoda          ###   ########.fr       */
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
		fdf_error("ERROR: Map error.");
	line = get_next_line(fd);
	if (!line)
		fdf_error("ERROR: Map empty.");
	tab = ft_split(line, ' ');
	while (tab[env->map_w]) //count width of map
	{
		free(tab[env->map_w]);
		env->map_w++;
	}
	while (line) //count height of map
	{
		free(line);
		env->map_h++;
		line = get_next_line(fd);
	}
	free(line);
	free(tab);
	close(fd);
}

void	cmap_heck_format(t_env *env, char *file)
{
	int		fd;
	char	*line;
	char	**tab;
	int		x;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd); //height
	while (line)
	{
		tab = ft_split(line, ' '); //width
		free(line);
		x = 0; //index of tab/width
		while (tab[x])
		{
			free(tab[x]);
			x++;
		}
		free(tab);
		if (x < env->map_w || x > env->map_w) //check if all line are same size
			fdf_error("ERROR: Wrong map format.");
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}

void	map_parse(t_env *env, char *line)
{
	int		fd;
	char	*line;
	char	**line_tab;

	fd = open(file, O_RDONLY);
	env->final_tab = malloc(sizeof(int *) * env->map_h); //malloc tab for height
	if (!env->final_tab)
		fdf_error("ERROR: Malloc failed.");
	while (env->y < env->map_h)
	{
		env->final_tab[env->y] = malloc(sizeof(int) * env->map_w); //malloc line for width
		if (!env->final_tab[env->y])
			fdf_error("ERROR: Malloc failed.");
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

int	map_env_init(t_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		free(env->mlx);
		return (MLX_ERROR);
	}
	env->win = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (env->win == NULL)
		return (MLX_ERROR);
	env->img = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env->addr = mlx_get_data_addr(env->image, &env->bpp,
			&env->line_len, &env->endian);
	point_two_dim(env);
	limits(env);
	h_management(env);
	mlx_loop_hook(env->mlx, render, env);
	mlx_loop(env->mlx);
	return (0);
}

int	map_render(t_env *env)
{
	draw_background(env);
	point_two_dim(env);
	limits(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
