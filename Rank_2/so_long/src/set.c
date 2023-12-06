/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:48:54 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/06 15:59:20 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img(t_data *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = "./xpm/[...].xpm";
	data->img.wall = "./xpm/[...].xpm";
	data->img.exit = "./xpm/[...].xpm";
	data->img.player = "./xpm/[...].xpm";
	data->img.collect = "./xpm/[...].xpm";
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.floor, &(data->img.width), &(data->img.height));
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.exit, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
}

void	set_content(t_cont *content)
{
	content->space = '0';
	content->wall = '1';
	content->exit = 'E';
	content->player = 'P';
	content->collect = 'C';
	content->count_e = 0;
	content->count_p = 0;
	content->count_c = 0;
}
