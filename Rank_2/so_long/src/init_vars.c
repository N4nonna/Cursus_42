/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:54:21 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/20 15:14:19 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_var_img(t_img *img)
{
	img->xpm_ptr = NULL;
	img->x = 0;
	img->y = 0;
}

static void	init_var_map(t_map *map)
{
	map->full = NULL;
	map->row = 0;
	map->column = 0;
	map->count_collect = 0;
	map->count_exit = 0;
	map->count_player = 0;
	map->collect = 0;
	map->exit = 0;
	map->player.x = 0;
	map->player.y = 0;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->move = 0;
	data->player_sprite = 0;
	data->map_alloc = 0;
	init_var_map(&data->map);
	init_var_img(&data->wall);
	init_var_img(&data->floor);
	init_var_img(&data->collect);
	init_var_img(&data->open_exit);
	init_var_img(&data->close_exit);
	init_var_img(&data->p_back);
	init_var_img(&data->p_front);
	init_var_img(&data->p_left);
	init_var_img(&data->p_right);
}
