/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:52:23 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/10 09:43:01 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_top(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y - 1][pos_x] != data->content.exit)
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("Number of step:%d\n", data->count);
		}
		else
		{
			if (count_collect(data) == 0)
			{
				ft_printf("Congrats! You win with %d steps!\n", data->count);
				end(data);
			}
		}
	}
}

void	move_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x - 1] != data->content.exit)
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("Number of step:%d\n", data->count);
		}
		else
		{
			if (count_collect(data) == 0)
			{
				ft_printf("Congrats! You win with %d steps!\n", data->count);
				end(data);
			}
		}
	}
}

void	move_down(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y + 1][pos_x] != data->content.exit)
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("Number of step:%d\n", data->count);
		}
		else
		{
			if (count_collect(data) == 0)
			{
				ft_printf("Congrats! You win with %d steps!\n", data->count);
				end(data);
			}
		}
	}
}

void	move_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x + 1] != data->content.exit)
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("Number of step:%d\n", data->count);
		}
		else
		{
			if (count_collect(data) == 0)
			{
				ft_printf("Congrats! You win with %d steps!\n", data->count);
				end(data);
			}
		}
	}
}
