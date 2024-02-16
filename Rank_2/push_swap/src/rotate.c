/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:20:25 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/16 15:31:52 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest_abv(t_stack *stack, int n)
{
	int	i;
	int	j;

	if (stack->top < 0 || n > max(stack))
		return (n);
	i = 0;
	j = max(stack);
	while (i <= stack->top)
	{
		if (stack->array[i] > n && stack->array[i] < j)
			j = stack->array[i];
		i++;
	}
	return (j);
}

int	closest_blw(t_stack *stack, int n)
{
	int	i;
	int	j;

	if (stack->top < 0 || n < min(stack))
		return (n);
	i = 0;
	j = min(stack);
	while (i <= stack->top)
	{
		if (stack->array[i] < n && stack->array[i] > j)
			j = stack->array[i];
		i++;
	}
	return (j);
}

void	rot_a(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->array[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		n_run(a, NULL, RRA, find + 1);
	else
		n_run(a, NULL, RA, a->top - find);
}

void	rot_b(t_stack *b, int n)
{
	int	find;

	find = b->top;
	while (find >= 0 && b->array[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < b->top / 2)
		n_run(NULL, b, RRB, find + 1);
	else
		n_run(NULL, b, RB, b->top - find);
}
