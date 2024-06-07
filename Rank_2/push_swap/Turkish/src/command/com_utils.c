/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:58:22 by manon             #+#    #+#             */
/*   Updated: 2024/06/07 15:13:56 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
