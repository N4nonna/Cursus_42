/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:58:30 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/15 16:03:07 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	n_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void	reverse_array(int *arr, size_t size)
{
	static int	i;

	if (i < size)
	{
		n_swap(arr[i++], arr[size - 1]);
		reverse_array(arr, size - 1);
	}
	i = 0;
}

//create stack and allocate memory
t_stack	*initialize(unsigned int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(*(stack->array)) * size);
	if (!stack->array)
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}
