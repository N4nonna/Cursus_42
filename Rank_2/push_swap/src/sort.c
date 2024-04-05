/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:03:40 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/05 12:25:14 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// verify if the stack is already sorted
bool	is_sort(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->top)
	{
		if (stack->array[i + 1] > stack->array[i])
			return (false);
	}
	return (true);
}

// define wich kind of sorting to do and create stack B
void	sort(t_stack *a)
{
	t_stack	*b;

	if (is_sort(a) || a->top == 0)
		return ;
	b = initialize(a->size);
	if (a->top < COMPLEXE_LIMIT)
		small_sort(a, b);
	else
		complex_sort(a, b);
	free_stack(b);
}
