/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:49:37 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/10 17:46:05 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_data *data, int new_y, int new_x, int player)
{
	int	x;
	int	y;

	data->player_sprite = player;
	x = data->map.player.x;
	y = data->map.player.y;
	if (data->map.full[new_y][new_x] == EXIT && data->map.count_collect == 0)
		victory(data);
	else if ((data->map.full[new_y][new_x] == FLOOR)
		|| (data->map.full[new_y][new_x] == COLLECT))
	{
		data->map.full[y][x] = FLOOR;
		if (data->map.full[new_y][new_x] == COLLECT)
			data->map.count_collect--;
		data->map.player.x = new_x;
		data->map.player.y = new_y;
		data->map.full[new_y][new_x] = PLAYER;
		data->move++;
		render_map(data);
	}
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		player_move(data, data->map.player.y - 1, data->map.player.x, BACK);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		player_move(data, data->map.player.y, data->map.player.x - 1, LEFT);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		player_move(data, data->map.player.y + 1, data->map.player.x, FRONT);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		player_move(data, data->map.player.y, data->map.player.x + 1, RIGHT);
	return (0);
}
