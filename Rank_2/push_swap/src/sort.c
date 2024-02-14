/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:03:40 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/14 19:27:33 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *a)
{
	int	*arr;

	arr = a->array;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		//RA
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		//RRA
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		//RRA + SA
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		//SA
	else
		//RA + SA
}

void	put_top(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_abv(a, top_b);
	if (to_move == top_b)
		to_move = min(a);
	rot_a(a, to_move);
	//PUSH A
}

void	comp_small_sort(t_stack *a, t_stack *b)
{
	//PUSH B
	small_sort(a, b);
	while (b->top >= 0)
		put_top(a, b);
	rot_a(a, 0);
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		// SWAP
	else if (a->top == 2)
		three_sort(a);
	else
		comp_small_sort(a, b);
}

void	sort(t_stack *a)
{
	t_stack	*b;

	if (is_sort(a) || a->top == 0)
		return ;
	if (a->top < COMPLEXE_LIMIT)
		small_sort(a, b);
	else
		complex_sort(a, b);
	free(b);
}
