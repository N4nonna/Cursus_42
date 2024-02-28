/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:03:55 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/28 12:22:33 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_steps(t_data *data)
{
	char	*move;
	char	*string;

	move = ft_itoa(data->move);
	if (!move)
		return ;
	string = ft_strjoin("Steps : ", move);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 40, 20, WHITE, string);
	free(move);
	move = NULL;
	free(string);
	string = NULL;
}

void	render_sprite(t_data *data, t_img sprite, int row, int column)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite.xpm_ptr, \
	column * sprite.x, row * sprite.y);
}

void	render_player(t_data *data, int y, int x)
{
	if (data->player_sprite == FRONT)
		render_sprite(data, data->p_front, y, x);
	if (data->player_sprite == LEFT)
		render_sprite(data, data->p_left, y, x);
	if (data->player_sprite == BACK)
		render_sprite(data, data->p_back, y, x);
	if (data->player_sprite == RIGHT)
		render_sprite(data, data->p_right, y, x);
}

void	identify_sprite(t_data *data, int y, int x)
{
	char	param;

	param = data->map.full[y][x];
	if (param == WALL)
		render_sprite(data, data->wall, y, x);
	else if (param == FLOOR)
		render_sprite(data, data->floor, y, x);
	else if (param == COLLECT)
		render_sprite(data, data->collect, y, x);
	else if (param == EXIT)
	{
		if (data->map.count_collect == 0)
			render_sprite(data, data->open_exit, y, x);
		else
			render_sprite(data, data->close_exit, y, x);
	}
	else if (param == PLAYER)
		render_player(data, y, x);
}

int	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.row)
	{
		x = 0;
		while (x < data->map.column)
		{
			identify_sprite(data, y, x);
			x++;
		}
		y++;
	}
	render_steps(data);
	ft_printf(CYAN"Steps: %d\n"RESET, data->move);
	return (0);
}
