/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:33:09 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/15 13:41:53 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strcmp(cmd, "SA"))
		swap(a);
	else if (ft_strcmp(cmd, "SB"))
		swap(b);
	else if (ft_strcmp(cmd, "PA"))
		push(b, a);
	else if (ft_strcmp(cmd, "PB"))
		push(a, b);
	else if (ft_strcmp(cmd, "RA"))
		rotate(a);
	else if (ft_strcmp(cmd, "RB"))
		rotate(b);
	else if (ft_strcmp(cmd, "RRA"))
		reverse_rot(a);
	else if (ft_strcmp(cmd, "RRB"))
		reverse_rot(b);
	ft_putendl_fd(cmd, STDOUT_FILENO);
}

void	n_run(t_stack *a, t_stack *b, char *cmd, int n)
{
	if (n <= 0)
		return ;
	run(a, b, cmd);
	n_run(a, b, cmd, n - 1);
}
