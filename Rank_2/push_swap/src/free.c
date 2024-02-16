/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:59:14 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/16 13:35:27 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

//if status, print status number and free all
void	error(t_stack *stack, char **array, int status)
{
	if (stack)
		free_stack(stack);
	if (array)
		free_array((void **)array);
	ft_putendl_fd(RED"Error\n"RESET, STDOUT_FILENO);
	exit(status);
}
