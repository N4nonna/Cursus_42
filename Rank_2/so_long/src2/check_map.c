/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:40:02 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/10 17:46:10 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_row(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.row)
	{
		if (data->map.full[i][0] != WALL)
			error("Invalid map. Wall missing in 1st row.(check_row)", data);
		else if (data->map.full[i][data->map.column - 1] != WALL)
			error("Invalid map. Wall missing in last row.(check_row)", data);
		i++;
	}
}

void	check_column(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.column)
	{
		if (data->map.full[0][i] != WALL)
			error("Invalid map.\
			Wall missing in 1st column.(check_column)", data);
		else if (data->map.full[data->map.row - 1][i] != WALL)
			error("Invalid map.\
			Wall missing in last column.(check_column)", data);
		i++;
	}
}

void	count_map_element(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.row)
	{
		x = 0;
		while (x < data->map.column)
		{
			if (!ft_strchr("CEP01", data->map.full[y][x]))
				error("Invalid map parameter.(count_map_element)", data);
			else if (data->map.full[y][x] == PLAYER)
			{
				data->map.count_player++;
				data->map.player.x = x;
				data->map.player.y = y;
			}
			else if (data->map.full[y][x] == COLLECT)
				data->map.count_collect++;
			else if (data->map.full[y][x] == EXIT)
				data->map.count_exit++;
			x++;
		}
		y++;
	}
}

void	verify_map_element(t_data *data)
{
	if (data->map.count_collect == 0)
		error("Invalid map. No collectibles.(verify_map_element)", data);
	else if (data->map.count_exit != 1)
		error("Invalid map. Wrong exit quantity.(verify_map_element)", data);
	else if (data->map.count_player != 1)
		error("Invalid map. Wrong player quantity.(verify_map_element)", data);
}

void	check_map(t_data *data)
{
	check_row(data);
	check_column(data);
	count_map_element(data);
	verify_map_element(data);
}
