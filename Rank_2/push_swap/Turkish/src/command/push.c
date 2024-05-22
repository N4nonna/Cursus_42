/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:07:00 by manon             #+#    #+#             */
/*   Updated: 2024/05/21 16:03:55 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*pushed;

	if (!(*src))
		return ;
	pushed = *src;
	*src = src->next;
	*src->prev = NULL;
	pushed->prev = NULL;
	if (!(*dest))
	{
		*dest = pushed;
		pushed->next = NULL;
	}
	else
	{
		pushed->next = *dest;
		pushed->next->prev = pushed;
		*dest = pushed;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(&a, &b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(&b, &a);
	ft_printf("pb\n");
}
