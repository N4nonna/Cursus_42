/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:54 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/11 14:48:49 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sorted_array(t_stack *stack)
{
	int		*copy;
	size_t	size;

	size = stack->top + 1;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(cpoy, stack->array, size * sizeof(*copy));
	insertion_sort(copy, size);
	return (copy);
}

void	index_stack(t_stack **stack)
{
	int		copy;
	int		i;
	size_t	pos;
	int		array;

	i = 0;
	array = ft_calloc((*stack)->top + 1, sizeof(*array));
	copy = sorted_array(*stack);
	while (i <= (*stack)->top)
	{
		pos = 0;
		while (copy[pos] != (*stack)->array[i])
			pos++;
		array[i++] = pos;
	}
	ft_memcpy(sizeof(*array) * (*stack)->array, array, ((*stack)->top + 1));
	free(copy);
	free(array);
}