/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:02:55 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/04 13:47:18 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_env	env;

	env.alpha = 7.37;
	env.translation = 1;
	env.scale = 30;
	env.altitude = 1;
	env.y = 0;
	env.map_h = 0;
	env.map_w = 0;
	env.map_path = av[1];
	if (ac == 2)
	{
		map_info(&env, env.map_path);
		map_check_format(&env, env.map_path);
		map_parse(&env, env.map_path);
		point_three_dim(&env);
		map_env_init(&env);
	}
	else
		fdf_error("ERROR: Wrong numbers of arguments. (main)");
	while (1)
		;
}

int	fdf_error(char *error_mess)
{
	ft_printf("%s\n", error_mess);
	exit (1);
}

void	fdf_free_tab(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->map_h)
	{
		free(env->final_tab[i]);
		i++;
	}
	free(env->final_tab);
}
