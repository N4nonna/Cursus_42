/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:20:10 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/29 15:05:26 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_data *data)
{
	int	i;

	i = 1;
	data->map.count_collect = 0;
	data->map.count_exit = 0;
	data->map.count_player = 0;
	data->move = 0;
	while (i < data->map.row)
	{
		if (ft_strlen(data->map.full[i - 1]) != ft_strlen(data->map.full[i]))
			error("Wrong map. Line of differents size (init_vars)", data);
		i++;
	}
	data->map.column = ft_strlen(data->map.full[0]);
	if ((data->map.row * IMG_HEIGHT > MAX_ROW)
		|| (data->map.column * IMG_WIDTH > MAX_COL))
		error("Wrong map. Map too big. (init_vars)", data);
	data->player_sprite = FRONT;
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		error("Can't find mlx pointer.(init_mlx)", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	data->map.column * IMG_WIDTH, data->map.row * IMG_HEIGHT, "so_long");
	if (data->win_ptr == NULL)
		error("Can't create window.(init_mlx)", data);
}

t_img	new_sprite(void *mlx, char *path, t_data *data)
{
	t_img	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error("No sprite found.(new_sprite)", data);
	return (sprite);
}

void	init_sprites(t_data *data)
{
	void	*mlx;

	mlx = data->mlx_ptr;
	data->wall = new_sprite(mlx, WALL_XPM, data);
	data->floor = new_sprite(mlx, FLOOR_XPM, data);
	data->collect = new_sprite(mlx, COLLECT_XPM, data);
	data->p_front = new_sprite(mlx, P_FRONT_XPM, data);
	data->p_left = new_sprite(mlx, P_LEFT_XPM, data);
	data->p_back = new_sprite(mlx, P_BACK_XPM, data);
	data->p_right = new_sprite(mlx, P_RIGHT_XPM, data);
	data->open_exit = new_sprite(mlx, OPEN_EXIT_XPM, data);
	data->close_exit = new_sprite(mlx, CLOSE_EXIT_XPM, data);
}
