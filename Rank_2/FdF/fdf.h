/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:17:10 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/03 13:37:10 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF
# define MLX_ERROR 1

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;


typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_vars;

#endif