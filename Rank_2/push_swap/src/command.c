/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:16:29 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/14 19:27:30 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push(t_stack *from, t_stack *to)
{
	if (from-> top == -1)
		return ;
	to->array[++to->top] = from->array[from->top--];
}

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->top];
	if (stack->top <= 0)
		return ;
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = tmp;
}
