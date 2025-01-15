/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:09:47 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/04/08 15:13:54 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_dlstsize_total(t_dlist *dlst)
{
	size_t		count;

	if (!dlst)
		return (0);
	count = 0;
	dlst = ft_dlstfirst(dlst);
	while (dlst)
	{
		dlst = dlst -> next;
		count++;
	}
	return (count);
}

size_t	ft_dlstsize_start(t_dlist *dlst)
{
	size_t		count;

	if (!dlst)
		return (0);
	count = 0;
	while (dlst)
	{
		dlst = dlst -> prev;
		count++;
	}
	return (count);
}

size_t	ft_dlstsize_end(t_dlist *dlst)
{
	size_t		count;

	if (!dlst)
		return (0);
	count = 0;
	while (dlst)
	{
		dlst = dlst -> next;
		count++;
	}
	return (count);
}
