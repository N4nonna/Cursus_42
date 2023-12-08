/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:17:10 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/08 13:08:44 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define MLX_ERROR 1

typedef struct s_img
{
	void	*img_floor;
	void	*img_wall;
	void	*img_exit;
	void	*img_player;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*exit;
	char	*wall;
	char	*floor;
	char	*collect;
}	t_img;

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_cont
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}	t_cont;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	int		count;
	char	**map;
	t_cont	content;
	t_img	img;
	t_pos	pos;

}	t_data;

//****** SET.C ******
void	set_content(t_cont *content);
void	set_img(t_data *data);

//****** MAP.C ******
void	map_free(t_data *data);
char	*map_get(int fd);
char	**map_parse(int fd, t_data *data);
char	**map_core(char **str, t_data *data);
int		map_check_square(char **map);

//****** CHECK_MAP.C ******
int		check_col(char *map_line, char wall, t_data *data);
int		check_line(char *map_line, char wall);
int		check_other(char *map_line, t_cont *content);
void	check_content(t_data *data);
int		check_rect(char **map);

//****** MAIN.C ******
int		error(char *error_mess);
int		count_collect(t_data *data);
int		end(t_data *data);
int		key_press(int keysym, t_data *data);
int		main(int ac, char **av);

//****** MOVE.C ******
void	move_top(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);

//****** RENDER.C ******
void	render_background(t_data *data);
void	render_other(t_data *data);
int		render(t_data *data);
void	render_core(t_data *data);
void	render_print_img(t_data *data, void *img, int x, int y);

//****** UTILS.C ******
char	**ft_error(char *error_mess);
char	**ft_free(t_data *data);
int		is_ber(const char *str);


#endif