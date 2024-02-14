/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:57:14 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/14 18:38:58 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifiy if all element are numbers (with only one sign)
bool	valid_int(char *element)
{
	bool			is_int;
	unsigned int	i;
	unsigned int	cm;

	i = 0;
	cm = 0;
	is_int = true;
	while (element[i] && is_int)
	{
		if (element[i] == '-' && cm < 1)
			cm++;
		else if (!ft_isdigit(element[i]))
			is_int = false;
		i++;
	}
	return (!is_int);
}

// ATOI but verify if there is an overflow and return this information only
bool	atoiv(const char *str, int *n)
{
	int		sign;
	bool	overflow;

	*n = 0;
	sign = -1;
	overflow = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = 1;
	while (*str >= '0' && *str <= '9')
	{
		*n = *n * 10 - (*str++ - '0');
		if (*n > 0 || (*n == INT_MIN && sign < 0))
			overflow = true;
	}
	*n *= sign;
	return (overflow);
}

// Verify if all numbers are differents
bool	double_int(int n, t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] == n)
			return (true);
		i--;
	}
	return (false);
}

// Verifiy if our args are valide, if not return status error.
// Free array after initializing it
int	fill_element(t_stack *stack, char *arg)
{
	unsigned int	j;
	int				n;
	int				status;
	char			**array;

	j = 0;
	status = 0;
	array = ft_split(arg, ' ');
	while (array[j] && !status)
	{
		if (valid_int(array[j]))
			status = 1;
		if (atoiv(array[j], &n))
			status = 2;
		if (double_int(n, stack))
			status = 3;
		else
			stack->array[++stack->top] = n;
		j++;
	}
	free_array((void **)array);
	return (status);
}

// Create stack and put all int inside
t_stack	*get_stack(int size, char **args)
{
	unsigned int	i;
	int				status;
	t_stack			*stack;

	if (size < 1)
		exit (0);
	i = 0;
	status = 0;
	stack = initialize(STACK_BUFFER);
	while (args[i] && !status)
		status = fill_element(stack, args[i++]);
	if (status)
		error(&stack, NULL, status);
	reverse_array(stack->array, stack->top + 1);
	return (stack);
}
