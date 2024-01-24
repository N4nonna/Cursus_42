/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:22:20 by mescoda           #+#    #+#             */
/*   Updated: 2024/01/24 12:25:40 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define IMG_HEIGHT 64
# define IMG_WIDTH 64

//MAP PARAMETERS

# define WALL '1'
# define FLOOR '0'
# define COLLECT 'C'
# define PLAYER 'P'
# define EXIT 'E'

//KEYS

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define KEY_Q 113
# define KEY_ESC 65307

# define FRONT 1
# define LEFT 2
# define RIGHT 3
# define BACK 4

//XPM SPRITES

# define WALL_XPM "./xpm/possum_wall.xpm"
# define FLOOR_XPM "./xpm/possum_floor.xpm"
# define COLLECT_XPM "./xpm/possum_collect1.xpm"
# define P_FRONT_XPM "./xpm/possum_front.xpm"
# define P_LEFT_XPM "./xpm/possum_left.xpm"
# define P_RIGHT_XPM "./xpm/possum_right.xpm"
# define P_BACK_XPM "./xpm/possum_back.xpm"
# define OPEN_EXIT_XPM "./xpm/trash_open.xpm"
# define CLOSE_EXIT_XPM "./xpm/trash_close.xpm"

//COLOR

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define WHITE 0xFFFFFF

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_map
{
	char	**full;
	int		row;
	int		column;
	int		count_collect;
	int		count_exit;
	int		count_player;
	int		collect;
	bool	exit;
	t_pos	player;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		move;
	int		player_sprite;
	bool	map_alloc;
	t_map	map;
	t_img	wall;
	t_img	floor;
	t_img	collect;
	t_img	open_exit;
	t_img	close_exit;
	t_img	p_front;
	t_img	p_left;
	t_img	p_back;
	t_img	p_right;
}	t_data;

//****** MAIN.C ******
int		main(int ac, char **av);

//****** INIT_MAP.C ******
void	check_args(int ac, char **av, t_data *data);
void	check_empty_line(char *map, t_data *data);
void	init_map(t_data *data, char *av);

//****** INIT_GAME.C ******
void	init_vars(t_data *data);
void	init_mlx(t_data *data);
t_img	new_sprite(void *mlx, char *path, t_data *data);
void	init_sprites(t_data *data);

//****** CHECK_MAP.C ******
void	check_row(t_data *data);
void	check_column(t_data *data);
void	count_map_element(t_data *data);
void	verify_map_element(t_data *data);
void	check_map(t_data *data);

//****** MAP_PARSING.C ******
void	free_matrix(char **matrix);
char	**blank_grid(t_data *data);
bool	flood_fill(t_map *map, t_pos point, char **grid);
void	check_path(t_data *data);

//****** RENDER_MAP.C ******
void	render_steps(t_data *data);
void	render_sprite(t_data *data, t_img sprite, int row, int column);
void	render_player(t_data *data, int y, int x);
void	identify_sprite(t_data *data, int y, int x);
int		render_map(t_data *data);

//****** HANDLE_INPUT.C ******
void	handle_exit(t_data *data, int new_y, int new_x, int player);
void	player_move(t_data *data, int new_y, int new_x, int player);
int		handle_input(int keysym, t_data *data);

//****** CLOSE.C ******
int		victory(t_data *data);
int		close_game(t_data *data);
int		error(char *message, t_data *data);

//****** END.C ******
void	free_map(t_data *data);
void	destroy_img(t_data *data);
void	free_all(t_data *data);

#endif
