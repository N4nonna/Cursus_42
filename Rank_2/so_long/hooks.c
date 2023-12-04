/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:15:24 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/04 13:52:24 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_managment(t_env *env)
{
	mlx_key_hook(env->win, hook_key, env);
	mlx_hook(env->win, 17, 0, hook_close, env);
}

int	hook_key(int key, t_env *env)
{
	if (key == 53)
		hook_close(env);
	return (0);
}

int	hook_close(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_display(env->mlx);
	exit (0);
}
