/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:18:14 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/10 14:54:31 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

//if status, print status number and free all
// !! Modify it so it's a text instead of an int !!
void	error(t_stack *stack, char **array, int status)
{
	if (stack)
		free_stack(stack);
	if (array)
		free_array((void **)array);
	ft_printf(RED"Error\n%s\n"RESET, status);
	exit(status);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = get_stack(ac - 1, &av[1]);
	index_stack(&stack);
	sort(stack);
	free_stack(stack);
	return (0);
}
