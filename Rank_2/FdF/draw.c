/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:30:02 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/04 13:59:22 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pxl(t_env *env, int x, int y, int color)
{
	char	*pixel;

	if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))
	{
		pixel = env->addr + (y * env->line_len + x * (env->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	draw_line(t_env *env, t_fpoint point0, t_fpoint point1)
{
	float	step;
	float	x;
	float	y;
	int		i;
	t_delta	delta;

	i = 0;
	delta.dx = point1.x - point0.x;
	delta.dy = point1.y - point0.y;
	if (fabsf(delta.dx) >= fabsf(delta.dy))
		step = fabsf(delta.dx);
	else
		step = fabsf(delta.dy);
	delta.dx = delta.dx / step;
	delta.dy = delta.dy / step;
	x = point0.x;
	y = point0.y;
	while (i < step)
	{
		draw_pxl(env, -x + WINDOW_WIDTH / 2 + env->translation,
			-y + WINDOW_HEIGHT / 2 + env->translation, WHITE);
		x = x + delta.dx;
		y = y + delta.dy;
		i++;
	}
}

void	draw_background(t_env *env, int color)
{
	int	h;
	int	w;

	h = 0;
	while (h < WINDOW_HEIGHT)
	{
		w = 0;
		while (w < WINDOW_WIDTH)
			draw_pxl(env, w++, h, color);
		h++;
	}
}
