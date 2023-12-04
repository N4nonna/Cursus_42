/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:17:10 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/04 14:45:24 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>

# define RED 0xFF0000
# define GREEN 0xFF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define MLX_ERROR 1

typedef struct s_ipoint
{
	int		x;
	int		y;
	int		z;
}	t_ipoint;

typedef struct s_fpoint
{
	float	x;
	float	y;
}	t_fpoint;

typedef struct s_delta
{
	float	dx;
	float	dy;
}	t_delta;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		*map_path;
	int			**final_tab;
	int			map_w;
	int			map_h;
	int			x; //width
	int			y; //height
	int			i;
	int			c_x;
	int			c_y;
	int			bpp;
	int			line_len;
	int			endian;
	int			scale;
	int			translation;
	float		altitude;
	float		zoom;
	float		alpha;
	t_ipoint	*init_points;
	t_fpoint	*final_points;
	t_delta		*delta;
}	t_env;

//****** FDF.C ******
int		fdf_error(char *error_mess);
void	fdf_free_tab(t_env *env);

//****** MAP.C ******
void	map_info(t_env *env, char *file);
void	map_check_format(t_env *env, char *file);
void	map_parse(t_env *env, char *line);
int		map_env_init(t_env *env);
int		map_render(t_env *env);

//****** POINT.C ******
void	point_three_dim(t_env *env);
void	point_two_dim(t_env *env);

//****** LIMITS.C ******
void	limits(t_env *env);
void	limit_no(t_env *env);
void	limit_right(t_env *env);
void	limit_low(t_env *env);

//****** HOOKS.C ******
void	hook_managment(t_env *env);
int		hook_key(int key, t_env *env);
int		hook_close(t_env *env);

//****** DRAW.C ******
void	draw_pxl(t_env *env, int x, int y, int color);
void	draw_line(t_env *env, t_fpoint point0, t_fpoint point1);
void	draw_background(t_env *env, int color);

#endif