/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:59:42 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/10 13:44:46 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_col(char *map_line, char wall, t_data *data)
{
	int	i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i -1] != wall)
	{
		error("Error\nColone not close with walls.(check_col)\n");
		return (0);
	}
	data->width = i;
	return (1);
}

int	check_line(char *map_line, char wall)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			error("Error\nLine not close with walls.(check_line)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_other(char *map_line, t_cont *content)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			error("Error\nToo many exit/player.(check_other)\n");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->space
			&& map_line[i] != content->exit && map_line[i] != content->player
			&& map_line[i] != content->collect)
		{
			error("Error\nUnknown symbol on map.(check_other)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_content(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.player)
				data->content.count_p += 1;
			if (data->map[i][y] == data->content.exit)
				data->content.count_e += 1;
			if (data->map[i][y] == data->content.collect)
				data->content.count_c += 1;
			y++;
		}
		y = 0;
		i++;
	}
}

int	check_rect(char **map)
{
	int	x;
	int	y;
	int	count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y])
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			error("Error\nWrong map format.(check_rect)\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
