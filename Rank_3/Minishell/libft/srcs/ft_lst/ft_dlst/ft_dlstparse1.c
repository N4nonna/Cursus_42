/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstparse1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:08:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/05 13:37:08 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist	*ft_dlstfirst(t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst -> prev != NULL)
		dlst = dlst -> prev;
	return (dlst);
}

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst -> next != NULL)
		dlst = dlst -> next;
	return (dlst);
}

t_dlist	*ft_dlstnth_next(t_dlist *dlst, size_t n)
{
	size_t	i;

	if (!dlst)
		return (NULL);
	i = 0;
	while (dlst -> next != NULL && i < n)
	{
		dlst = dlst -> next;
		i++;
	}
	return (dlst);
}

t_dlist	*ft_dlstnth_prev(t_dlist *dlst, size_t n)
{
	size_t	i;

	i = 0;
	if (!dlst)
		return (NULL);
	while (dlst -> prev != NULL && i < n)
	{
		dlst = dlst -> prev;
		i++;
	}
	return (dlst);
}
