/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:01:55 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/03 16:40:48 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point_three_dim(t_env *env)
{
	int	i;

	i = 0;
	env->init_points = malloc(sizeof(t_ipoint) * env->map_h * env->map_w);
	if (!env->init_points)
		fdf_error("ERROR: Malloc failed.");
	env->y = 0;
	while (env->y < env->map_h)
	{
		env->x = 0;
		while (env->x < env->map_w) //init points of map
		{
			env->init_points[i] = (t_ipoint){env->x, env->y,
				env->final_tab[env->y][env->x]};
			i++;
			env->x++;
		}
		env->y++;
	}
	fdf_free_tab(env);
}

void	point_two_dim(t_env *env)
{
	int	i;

	i = 0;
	env->final_points = malloc(sizeof(t_fpoint) * env->map_h * env->map_w);
	if (!env->final_points)
		fdf_error("ERROR: Malloc failed (point_two_dim).");
	while (i < (env->map_w * env->map_h)) //transform 3D into 2D
	{
		env->final_points[i].y = env->init_points[i].y \
			* cosf(env->alpha) + env->init_points[i].y \
			* cosf(env->alpha + 2) \
			+ (env->init_points[i].z * env->altitude) \
			* cosf(env->alpha - 2);
		env->final_points[i].x = env->init_points[i].x \
			* sinf(env->alpha) + env->init_points[i].y \
			* sinf(env->alpha + 2) \
			+ (env->init_points[i].z * env->altitude) \
			* sinf(env->alpha - 2);
		env->final_points[i].x *= -env->scale;
		env->final_points[i].y *= env->scale;
		i++;
	}
}
