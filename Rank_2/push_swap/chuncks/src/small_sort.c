/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:22:13 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/20 17:49:45 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// with three number we have just five possibility
void	three_sort(t_stack *a)
{
	int	*arr;

	arr = a->array;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		run(a, NULL, SA);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		run(a, NULL, RRA);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		run(a, NULL, SA);
		run(a, NULL, RRA);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		run(a, NULL, RA);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		run(a, NULL, SA);
		run(a, NULL, RA);
	}
}

// compare number n in stack B to first number in stack A
// and push N to stack A top or bottom
void	put_top(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_abv(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = min(a);
	rot_a(a, to_move);
	run(a, b, PA);
}

// put two first number in stack B, sort the three number left
// and push stack B in stack A
void	comp_small_sort(t_stack *a, t_stack *b)
{
	n_run(a, b, PB, a->top - 2);
	three_sort(a);
	while (b->top >= 0)
		put_top(a, b);
	rot_a(a, 0);
}

// depending of how many number we have, define wich function is better
void	small_sort(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		run(a, NULL, SA);
	else if (a->top == 2)
		three_sort(a);
	else
		comp_small_sort(a, b);
}
