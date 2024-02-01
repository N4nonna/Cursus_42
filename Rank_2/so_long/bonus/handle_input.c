/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:49:37 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/01 11:34:00 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_exit(t_data *data, int new_y, int new_x, int player)
{
	int	x;
	int	y;

	data->player_sprite = player;
	x = data->map.player.x;
	y = data->map.player.y;
	data->map.full[y][x] = EXIT;
	data->map.count_exit++;
	if (data->map.full[new_y][new_x] == COLLECT)
		data->map.count_collect--;
	data->map.player.x = new_x;
	data->map.player.y = new_y;
	data->map.full[new_y][new_x] = PLAYER;
	data->move++;
	render_map(data);
}

void	player_move(t_data *data, int new_y, int new_x, int player)
{
	int	x;
	int	y;

	data->player_sprite = player;
	x = data->map.player.x;
	y = data->map.player.y;
	if ((data->map.full[new_y][new_x] == EXIT && data->map.count_collect == 0))
		victory(data);
	else if (data->map.full[new_y][new_x] == ENEMY)
		game_over(data);
	else if (data->map.full[new_y][new_x] != WALL)
	{
		if (data->map.full[y][x] == PLAYER && data->map.count_exit == 0)
			handle_exit(data, new_y, new_x, player);
		data->map.full[y][x] = FLOOR;
		if (data->map.full[new_y][new_x] == COLLECT)
			data->map.count_collect--;
		else if (data->map.full[new_y][new_x] == EXIT)
			data->map.count_exit--;
		data->map.player.x = new_x;
		data->map.player.y = new_y;
		data->map.full[new_y][new_x] = PLAYER;
		data->move++;
		render_map(data);
	}
}

int	handle_input(int keysym, t_data *data)
{
	move_enemy(data);
	if (keysym == KEY_UP || keysym == KEY_W)
		player_move(data, data->map.player.y - 1, data->map.player.x, BACK);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		player_move(data, data->map.player.y, data->map.player.x - 1, LEFT);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		player_move(data, data->map.player.y + 1, data->map.player.x, FRONT);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		player_move(data, data->map.player.y, data->map.player.x + 1, RIGHT);
	if (keysym == KEY_ESC || keysym == KEY_Q)
		close_game(data);
	return (0);
}
