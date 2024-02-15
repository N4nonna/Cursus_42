/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:26:13 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/15 13:42:21 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	n_min(int *arr, size_t len)
{
	int		m;

	if (len == 1)
		return (array[0]);
	m = n_min(arr, len - 1);
	if (arr[len - 1] < m)
		m = arr[len - 1];
	return (m);
}

int	min(t_stack *stack)
{
	return (n_min(stack->array, stack->top + 1));
}

static int	n_max(int *arr, size_t len)
{
	int		m;

	if (len == 1)
		return (array[0]);
	m = n_max(arr, len - 1);
	if (arr[len - 1] > m)
		m = arr[len - 1];
	return (m);
}

int	max(t_stack *stack)
{
	return (n_max(stack->array, stack->top + 1));
}
