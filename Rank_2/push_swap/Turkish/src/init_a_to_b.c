/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:15:42 by manon             #+#    #+#             */
/*   Updated: 2024/05/17 14:07:59 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack		*curr_b;
	t_stack		*target;
	long int	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->nbr < a->nbr && curr_b->nbr > best_match)
			{
				best_match = curr_b->nbr;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = len_a - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - a->target_node->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long int	cheapest_val;
	t_stack		*cheapest_node;

	if (!stack)
		return ;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_val)
		{
			cheapest_val = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	current_index(t_stack *stack)
{
	int	i;
	int	med;

	if (!stack)
		return ;
	med = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= med)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_node_a(t_stack **a, t_stack **b)
{
	current_index(*a);
	current_index(*b);
	set_target_a(*a, *b);
	cost_analysis_a(*a, *b);
	set_cheapest(*a);
}
