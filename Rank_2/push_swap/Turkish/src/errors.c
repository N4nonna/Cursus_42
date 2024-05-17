/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:13:27 by mescoda           #+#    #+#             */
/*   Updated: 2024/05/17 16:11:12 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	error_syntax(char *str)
{
	int	i;

	if (!str)
		return (true);
	if ((str[0] != '+' || str[0] != '-') || !(str[0] >= 0 && str[0] <= 9))
		return (true);
	i = 1;
	while (str[i])
	{
		if (!(str[i] >= 0 && str[i] <= 9))
			return (true);
		i++;
	}
	return (false);
}

bool	error_dup(t_stack *a, int n)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nbr == n)
			return (true);
		a = a->next;
	}
	return (false);
}

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
