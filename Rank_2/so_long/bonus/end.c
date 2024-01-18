/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:35:22 by mescoda           #+#    #+#             */
/*   Updated: 2024/01/04 15:21:22 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.row)
		free(data->map.full[i++]);
	free(data->map.full);

}

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->floor.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->collect.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->p_back.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->p_front.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->p_left.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->p_right.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->p_dead.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->enemy.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->close_exit.xpm_ptr);
	mlx_destroy_image(data->mlx_ptr, data->open_exit.xpm_ptr);
}

void	free_all(t_data *data)
{
	destroy_img(data);
	free_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}
