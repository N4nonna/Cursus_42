/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:49:22 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/04 12:12:30 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	limits(t_env *env)
{
	env->c_y = 1;
	env->i = 0;
	while (env->c_y != env->map_h)
	{
		env->c_x = 1;
		while (env->c_x < env->map_w) //start drawing points together
			limit_no(env); //right to left
		if (env->c_x == env->map_w)
		{
			limit_low(env); //end of line
			env->i++;
		}
		env->c_y++; //new line
	}
	env->c_x = 1;
	if (env->c_y == env->map_h) //last line
	{
		while (env->c_x != env->map_w)
		{
			limit_right(env);
			env->i++;
		}
	}
	free (env->final_points);
}

void	limit_no(t_env *env)
{
	limit_right(env); //diagonal line right to left
	limit_low(env);//diagonal line up to down
	env->i++;
}

void	limit_right(t_env *env)
{
	float	x0; //right
	float	x1; // left
	float	y0; // up
	float	y1; // down

	x0 = env->final_points[env->i].x;
	y0 = env->final_points[env->i].y;
	x1 = env->final_points[env->i + 1].x;
	y1 = env->final_points[env->i + 1].y;
	env->c_x++;
	draw_line(env, (t_fpoint){x0, y0}, (t_fpoint){x1, y1});
}

void	limit_low(t_env *env)
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;

	x0 = env->final_points[env->i].x;
	y0 = env->final_points[env->i].y;
	x1 = env->final_points[env->i + env->map_w].x;
	y1 = env->final_points[env->i + env->map_h].y;
	draw_line(env, (t_fpoint){x0, y0}, (t_fpoint){x1, y1});
}
