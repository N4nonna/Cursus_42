/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:12:08 by mescoda           #+#    #+#             */
/*   Updated: 2024/01/04 15:14:41 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	check_args(ac, av, data);
	init_map(data, av[1]);
	init_vars(data);
	check_map(data);
	init_mlx(data);
	init_sprites(data);
	render_map(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, close_game, data);
	mlx_hook(data->win_ptr, Expose, ExposureMask, render_map, data);
	mlx_loop(data->mlx_ptr);
	free_all(data);
}
