/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:08:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/26 18:03:10 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_dlstindex_next(t_dlist *dlst_start, void *content)
{
	t_dlist	*focus;
	size_t	i;

	if (!dlst_start)
		return (-2);
	focus = dlst_start;
	i = 0;
	while (focus -> next != NULL)
	{
		focus = focus -> next;
		if (focus -> content == content)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_dlstindex_prev(t_dlist *dlst_start, void *content)
{
	t_dlist	*focus;
	size_t	i;

	if (!dlst_start)
		return (-2);
	focus = dlst_start;
	i = 0;
	while (focus -> prev != NULL)
	{
		focus = focus -> prev;
		if (focus -> content == content)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_dlstrank_next(t_dlist *dlst_from, t_dlist *current)
{
	t_dlist	*focus;
	size_t	i;

	if (!dlst_from || !current)
		return (-2);
	focus = dlst_from;
	i = 0;
	while (focus -> next != NULL)
	{
		focus = focus -> next;
		if (focus == current)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_dlstrank_prev(t_dlist *dlst_from, t_dlist *current)
{
	t_dlist	*focus;
	size_t	i;

	if (!dlst_from || !current)
		return (-2);
	focus = dlst_from;
	i = 0;
	while (focus -> prev != NULL)
	{
		focus = focus -> prev;
		if (focus == current)
			return (i);
		i++;
	}
	return (-1);
}
