/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:42:31 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/03 13:37:05 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	render(t_vars *vars)
{
	if (vars->win == NULL)
		return (1);
	render_background(&vars->img, WHITE_PIXEL);
	render_rect(&vars->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
		100, 100, GREEN_PIXEL});
	render_rect(&vars->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);

	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "TEST");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (MLX_ERROR);
	}
	vars.img.mlx_img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.mlx_img, &vars.img.bpp,
			&vars.img.line_len, &vars.img.endian);
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &handle_keypress, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img.mlx_img);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
