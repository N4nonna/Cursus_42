/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstparse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:05:57 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/05 13:31:41 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lstindex(t_list *lst_from, void *content)
{
	t_list	*focus;
	size_t	i;

	if (!lst_from)
		return (-2);
	focus = lst_from;
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

int	ft_lstrank(t_list *lst_from, t_list *current)
{
	t_list	*focus;
	size_t	i;

	if (!lst_from || !current)
		return (-2);
	focus = lst_from;
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
