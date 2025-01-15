/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstparse1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:05:57 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/06/05 12:38:33 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_list	*ft_lstnth(t_list *lst, size_t n)
{
	size_t	i;

	if (!lst)
		return (NULL);
	i = 0;
	while (lst -> next != NULL && i < n)
	{
		lst = lst -> next;
		i++;
	}
	return (lst);
}

t_list	*ft_lstprev(t_list *lst_from, t_list *current)
{
	t_list	*focus;
	size_t	i;

	if (!lst_from || !current)
		return (NULL);
	focus = lst_from;
	i = 0;
	while (focus -> next != NULL)
	{
		focus = focus -> next;
		if (focus -> next == current)
			return (focus);
		i++;
	}
	return (NULL);
}

size_t	ft_lstsize(t_list *lst)
{
	int		count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
