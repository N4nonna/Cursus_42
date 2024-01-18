/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:34:28 by mescoda           #+#    #+#             */
/*   Updated: 2024/01/04 15:30:08 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	victory(t_data *data)
{
	ft_printf(CYAN"\nSteps: %d\n"RESET, ++data->move);
	free_all(data);
	ft_printf(GREEN"\nYOU WIN !!!!!\n"RESET);
	exit(EXIT_FAILURE);
}

int	game_over(t_data *data)
{
	int	x;
	int	y;

	data->player_sprite = 5;
	x = data->map.player.x;
	y = data->map.player.y;
	data->map.full[y][x] = DEAD;
	render_map(data);
	ft_printf(CYAN"\nSteps: %d\n"RESET, ++data->move);
	free_all(data);
	ft_printf(RED"\nGAME OVER ! :(\n"RESET);
	exit(EXIT_FAILURE);
}

int	close_game(t_data *data)
{
	ft_printf(CYAN"Steps: %d\n"RESET, data->move);
	ft_printf(GREY"CLOSED\n"RESET);
	exit(EXIT_FAILURE);
}

int	error(char *message, t_data *data)
{
	if (data->map_alloc == true)
		free_map(data);
	free(data);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit(EXIT_FAILURE);
}
