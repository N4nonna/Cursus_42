/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:31:15 by mabonny-          #+#    #+#             */
/*   Updated: 2024/06/05 13:57:22 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	lst -> content = NULL;
	free(lst);
	lst = NULL;
}

void	ft_lstremove(t_list **alst_from, t_list *target, void (*del)(void*))
{
	if (!*alst_from || !target)
		return ;
	if (target == *alst_from)
	{
		*alst_from = target -> next;
		ft_lstdelone(target, del);
	}
	else
	{
		target = ft_lstprev(*alst_from, target);
		if (!target)
			return ;
		target -> next = target -> next -> next;
		ft_lstdelone(target -> next, del);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**p_eye;
	t_list	*eye;

	if ((!lst))
		return ;
	p_eye = lst;
	while (*p_eye != NULL)
	{
		eye = (*p_eye)->next;
		ft_lstdelone(*p_eye, del);
		(*p_eye) = eye;
	}
	lst = NULL;
}
