/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:13:17 by mescoda           #+#    #+#             */
/*   Updated: 2023/12/10 18:08:46 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	victory(t_data *data)
{
	ft_printf(CYAN"\nSteps: %d\n"RESET, ++data->move);
	free_all(data);
	ft_printf(GREEN"\nYOU WIN !!!!!!"RESET);
	exit (EXIT_FAILURE);
}

int	close_game(t_data *data)
{
	ft_printf(CYAN"Steps: %d\n"RESET, data->move);
	free_all(data);
	ft_printf(GREY"Closed.\n"RESET);
	exit (EXIT_FAILURE);
}

int	error(char *message, t_data *data)
{
	if (data->map_alloc == true)
		free_map(data);
	free(data);
	ft_printf(RED"ERROR\n"GREY"%s\n"RESET, message);
	exit (EXIT_FAILURE);
}
