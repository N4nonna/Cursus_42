/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:07:00 by manon             #+#    #+#             */
/*   Updated: 2024/05/21 15:47:02 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	swap(t_stack **stack)
{
	t_stack	*top;

	if (!(*stack) || !(*stack)->next)
		return ;
	top = *stack;
	*stack = *stack->next;
	*stack->prev = NULL;
	if (*stack->next)
	{
		top->next = *stack->next;
		*stack->next->next = *stack->next;
	}
	*stack->next = top;
}

void	sa(t_stack **a)
{
	swap(&a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(&b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(&a);
	swap(&b);
	ft_printf("ss\n");
}
