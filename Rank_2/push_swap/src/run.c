/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:33:09 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/16 16:36:22 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_streq(const char *s1, const char *s2)
{
	return (!(ft_strncmp(s1, s2, ft_strlen(s2) + 1)));
}

void	run(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_streq(cmd, SA))
		swap(a);
	else if (ft_streq(cmd, SB))
		swap(b);
	else if (ft_streq(cmd, PA))
		push(b, a);
	else if (ft_streq(cmd, PB))
		push(a, b);
	else if (ft_streq(cmd, RA))
		rotate(a);
	else if (ft_streq(cmd, RB))
		rotate(b);
	else if (ft_streq(cmd, RRA))
		reverse_rotate(a);
	else if (ft_streq(cmd, RRB))
		reverse_rotate(b);
	ft_putendl_fd(cmd, STDOUT_FILENO);
}

void	n_run(t_stack *a, t_stack *b, char *cmd, int n)
{
	if (n <= 0)
		return ;
	run(a, b, cmd);
	n_run(a, b, cmd, n - 1);
}
