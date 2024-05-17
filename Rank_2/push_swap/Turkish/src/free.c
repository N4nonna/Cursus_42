/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:13:03 by mescoda           #+#    #+#             */
/*   Updated: 2024/05/17 16:34:33 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack **stack)
{
	if (stack)
		free_stack(stack);
	ft_putendl_fd(RED"Error\n"RESET, STDOUT_FILENO);
	exit(0);
}

static void	free_stack(t_stack **stack)
{
	while (*stack)
	{
		free(stack);
		stack = stack->next;
	}
	free(*stack);
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(&a);
	free_stack(&b);
}
