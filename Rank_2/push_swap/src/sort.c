/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:03:40 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/19 18:32:37 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
