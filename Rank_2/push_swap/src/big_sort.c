/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:23:41 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/05 13:59:06 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort stack A
void	move_top(t_stack *a, int min, int max)
{
	int	i;
	int	index[2];

	index[0] = from_top(a, min, max);
	index[1] = from_bottom(a, min, max);
	if (index[0] < a->top - index[1])
		i = index[0];
	else
		i = index[1];
	rot_a(a, a->array[i]);
}

// sort stack B
void	move_min_max(t_stack *b)
{
	int	i;
	int	index[2];

	index[0] = n_index(b, min(b));
	index[1] = n_index(b, max(b));
	if (index[0] < b->top - index[1])
		i = index[0];
	else
		i = index[1];
	rot_b(b, b->array[i]);
}

static void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top)
	{
		move_min_max(b);
		put_top(a, b);
	}
}

// move chunk from stack A to stack B after sorting this chunk
static void	move_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size)
	{
		move_top(a, min, max);
		run(a, b, PB);
		size--;
	}
}

// create 3 chunk, push one in stack B, sort this chunk and 
// repush it in stack A until everything is sorted
void	complex_sort(t_stack *a, t_stack *b)
{
	size_t	chunk;
	size_t	step;
	int		_min;
	int		_max;

	chunk = (a->top + 1) / CONST_CHUNK + 1;
	step = (a->top + 1) / chunk;
	_max = max(a);
	while (chunk >= 1)
	{
		if (chunk == 1)
			_min = min(a);
		else
			_min = _max - step + 1;
		move_chunk(a, b, _min, _max);
		sort_chunk(a, b);
		_max = _min - 1;
		chunk--;
	}
	rot_a(a, min(a));
}
