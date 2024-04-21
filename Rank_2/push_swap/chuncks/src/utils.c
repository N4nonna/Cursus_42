/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:58:30 by mescoda           #+#    #+#             */
/*   Updated: 2024/04/05 12:04:46 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	from_bottom(t_stack *stack, int min, int max)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] >= min && stack->array[i] <= max)
			return (i);
		i--;
	}
	return (-1);
}

int	from_top(t_stack *stack, int min, int max)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->array[i] >= min && stack->array[i] <= max)
			return (i);
		i++;
	}
	return (-1);
}

void	reverse_array(int *arr, size_t size)
{
	static size_t	i;

	if (i < size)
	{
		ft_swap(&arr[i++], &arr[size - 1]);
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
