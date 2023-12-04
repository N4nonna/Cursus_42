/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:58:02 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/04 16:10:32 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render_env_init(t_env *env)
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
	env->addr = mlx_get_data_addr(env->img, &env->bpp,
			&env->line_len, &env->endian);
	point_two_dim(env);
	limits(env);
	hook_managment(env);
	mlx_loop_hook(env->mlx, map_render, env);
	mlx_loop(env->mlx);
	return (0);
}

int	render(t_env *env)
{
	draw_background(env, BLACK);
	point_two_dim(env);
	limits(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}