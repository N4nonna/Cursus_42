/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:54 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/19 18:02:20 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *arr, size_t size)
{
	int		i;
	size_t	j;
	int		k;

	j = 1;
	while (j < size)
	{
		i = j - 1;
		k = arr[j++];
		while (i >= 0 && arr[i + 1] < arr[i])
		{
			arr[i + 1] = arr[i];
			arr[i--] = k;
		}
	}
}

static int	*sorted_array(t_stack *stack)
{
	int		*copy;
	size_t	size;

	size = stack->top + 1;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(copy, stack->array, size * sizeof(*copy));
	insertion_sort(copy, size);
	return (copy);
}

void	index_stack(t_stack **stack)
{
	int		*copy;
	int		i;
	size_t	pos;
	int		*array;

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
	ft_memcpy((*stack)->array, array, ((*stack)->top + 1) * sizeof(*array));
	free(copy);
	free(array);
}

int	n_index(t_stack *stack, int n)
{
	int	i;

	i = stack->top;
	while (stack->array[i] != n && i >= 0)
		i--;
	return (i);
}
