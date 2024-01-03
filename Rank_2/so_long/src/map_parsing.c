/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:38:46 by mescoda           #+#    #+#             */
/*   Updated: 2024/01/03 13:30:19 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	if (i > 0)
		free(matrix);
	matrix = NULL;
}

char	**blank_grid(t_data *data)
{
	int		i;
	char	**blank_grid;

	i = 0;
	blank_grid = ft_calloc((data->map.row + 1), sizeof(char *));
	if (!blank_grid)
		return (NULL);
	while (i < data->map.row)
	{
		blank_grid[i] = ft_strdup(data->map.full[i]);
		if (!blank_grid[i])
		{
			free_matrix(blank_grid);
			error("Invalid malloc allocation.(blank_grid)", data);
		}
		i++;
	}
	return (blank_grid);
}

bool	flood_fill(t_map *map, t_pos point, char **grid)
{
	if (grid[point.y][point.x] == WALL)
		return (false);
	else if (grid[point.y][point.x] == COLLECT)
		map->collect++;
	else if (grid[point.y][point.x] == EXIT)
		map->exit = true;
	grid[point.y][point.x] = WALL;
	flood_fill(map, (t_pos){point.x + 1, point.y}, grid);
	flood_fill(map, (t_pos){point.x - 1, point.y}, grid);
	flood_fill(map, (t_pos){point.x, point.y + 1}, grid);
	flood_fill(map, (t_pos){point.x, point.y - 1}, grid);
	return (map->collect == map->count_collect && map->exit);
}

void	check_path(t_data *data)
{
	char	**grid;

	data->map.collect = 0;
	data->map.exit = false;
	grid = blank_grid(data);
	if (!flood_fill(&data->map, data->map.player, grid))
	{
		free_matrix(grid);
		error("Invalid map.\
		Can't access exit and/or collectibles.(check_path)", data);
	}
	free_matrix(grid);
}
