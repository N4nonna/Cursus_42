/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:57:39 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/15 18:01:07 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define STACK_BUFFER
# define INT_MIN

typedef struct s_stack
{
	int	*array;
	int	top;
	int	size;
}	t_stack;

// MAIN.C
int		main(int ac, char **av);

// CHECK_ARGS.C
t_stack	*get_stack(int size, char **args);
int		fill_element(t_stack *stack, char *arg);

// INDEX.C
void	index_stack(t_stack **stack);

// SORT.C
void	sort(t_stack *a);
bool	is_sort(t_stack *stack);

// SMALL_SORT.C
void	small_sort(t_stack *a, t_stack *b);
void	comp_small_sort(t_stack *a, t_stack *b);
void	put_top(t_stack *a, t_stack *b);
void	three_sort(t_stack *a);

// ROTATE.C
void	rot_b(t_stack *b, int n);
void	rot_a(t_stack *a, int n);
int		closest_blw(t_stack *stack, int n);
int		closest_abv(t_stack *stack, int n);

// MIN_MAX.C
int		max(t_stack *stack);
int		min(t_stack *stack);

// RUN.C
void	n_run(t_stack *a, t_stack *b, char *cmd, int n);
void	run(t_stack *a, t_stack *b, char *cmd);

// COMMAND.C
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);

// FREE.C
void	error(t_stack *stack, char **array, int status);
void	free_stack(t_stack *stack);
void	free_array(void **array);

// UTILS.C
t_stack	*initialize(unsigned int size);
void	reverse_array(int *arr, size_t size);

#endif