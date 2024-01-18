#include "so_long.h"

int	enemy_ver(t_data *data)
{
	int	y;
	int	x;

	y = data->map.enemy.y;
	x = data->map.enemy.x;
	if (data->map.full[y - 1][x] == FLOOR)
	{
		data->map.full[y][x] = FLOOR;
		data->map.enemy.y = y - 1;
		data->map.full[y - 1][x] = ENEMY;
		return (1);
	}
	else if (data->map.full[y + 1][x] == FLOOR)
	{
		data->map.full[y + 1][x] = FLOOR;
		data->map.enemy.y = y + 1;
		data->map.full[y + 1][x] = ENEMY;
		return (1);
	}
	return (0);
}

int	enemy_hor(t_data *data)
{
	int	y;
	int	x;

	y = data->map.enemy.y;
	x = data->map.enemy.x;
	if (data->map.full[y][x - 1] == FLOOR)
	{
		data->map.full[y][x] = FLOOR;
		data->map.enemy.x = x - 1;
		data->map.full[y][x - 1] = ENEMY;
		return (1);
	}
	else if (data->map.full[y][x + 1] == FLOOR)
	{
		data->map.full[y][x + 1] = FLOOR;
		data->map.enemy.x = x + 1;
		data->map.full[y][x + 1] = ENEMY;
		return (1);
	}
	return (0);
}

void	move_enemy(t_data *data)
{
	int	dir;

	dir = data->enemy.dir;
	if (dir == 1)
	{
		if (!enemy_ver(data))
			enemy_hor(data);
		dir = 0;
	}
	else
	{
		if (!enemy_hor(data))
			enemy_ver(data);
		dir = 1;
	}
}
