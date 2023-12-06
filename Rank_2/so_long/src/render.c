/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:11 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/06 18:17:01 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.wall)
				render_print_img(data, data->img.wall, i, y);
			if (data->map[y][i] == data->content.space)
				render_print_img(data, data->img.floor, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

void	render_other(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[y])
	{
		if (data->map[y][i] == data->content.exit)
			render_print_img(data, data->img.exit, i, y);
		if (data->map[y][i] == data->content.collect)
			render_print_img(data, data->img.collect, i, y);
		if (data->map[y][i] == data->content.player)
		{
			data->pos.x = i * data->img.width;
			data->pos.y = y * data->img.height;
			render_print_img(data, data->img.player, i, y);
		}
		i++;
	}
	i = 0;
	y++;
}

int	render(t_data *data)
{
	render_background(data);
	render_other(data);
	return (0);
}

void	render_core(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.width),
			(data->height * data->img.height), "so_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data, 17, 0, &end, &data);
	mlx_loop(data->mlx_ptr);
	end(data);
}

void	render_print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		img, data->img.width * x, data->img.height * y);
}
