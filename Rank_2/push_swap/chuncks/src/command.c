/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:16:29 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/05 12:54:18 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// RA or RB
void	rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->top + 1;
	tmp = stack->array[stack->top];
	while (--i)
		stack->array[i] = stack->array[i - 1];
	stack->array[0] = tmp;
}

// RRA or RRB
void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->array[0];
	while (++i < stack->top)
		stack->array[i] = stack->array[i + 1];
	stack->array[stack->top] = tmp;
}

// PA or PB
void	push(t_stack *from, t_stack *to)
{
	if (from->top == -1)
		return ;
	to->array[++to->top] = from->array[from->top--];
}

// SA or SB
void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->top];
	if (stack->top <= 0)
		return ;
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = tmp;
}
