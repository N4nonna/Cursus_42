/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:12:48 by manon             #+#    #+#             */
/*   Updated: 2024/06/12 14:29:08 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	intit_stack(t_stack **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_error(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a);
		if (error_dup(*a, (int)n))
			free_error(a);
		append_node(a, (int)n);
		i++;
	}
}
