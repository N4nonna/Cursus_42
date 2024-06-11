/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manon <manon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:21:37 by manon             #+#    #+#             */
/*   Updated: 2024/06/09 14:33:28 by manon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft.h"

# define RED "\033[1;31m"
# define RESET "\033[0m"

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
void	init_node_a(t_stack *a, t_stack *b);

// init_b_to_a.c
void	init_node_b(t_stack *a, t_stack *b);

// utils.c
t_stack	*find_last(t_stack *stack);
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
void	free_stack(t_stack **stack);

// ****** COMMAND FUNCTIONS ******

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
t_stack	*get_cheapest(t_stack *stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	prep_for_push(t_stack **stack, t_stack *top_node, char name);

#endif