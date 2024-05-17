/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:21:37 by manon             #+#    #+#             */
/*   Updated: 2024/05/17 16:34:56 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft.h"

// ****** STRUCT ******

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// ****** SRC FUNCTIONS ******

// main.c
int		main(int ac, char **av);

// init_stack.c
void	intit_stack(t_stack **a, char **av);

//sort_three.c
void	sort_three(t_stack **a);

// sort_stack.c
void	sort_stack(t_stack **a, t_stack **b);

// init_a_to_b.c
void	set_cheapest(t_stack *stack);
void	current_index(t_stack *stack);
void	init_node_a(t_stack **a, t_stack **b);

// init_b_to_a.c
void	init_node_b(t_stack *a, t_stack *b);

// utils.c
long	ft_atol(char *str);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
int		stack_len(t_stack *stack);

// errors.c
bool	error_syntax(char *str);
bool	error_dup(t_stack *a, int n);
bool	is_sorted(t_stack *stack);

// free.c
void	free_error(t_stack **stack);
void	free_all(t_stack *a, t_stack *b);

// ****** COMMAND FUNCTIONS ******



#endif