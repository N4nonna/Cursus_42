/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:07:43 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/05 13:35:37 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (!dlst)
		return ;
	if (del)
		del(dlst->content);
	dlst -> content = NULL;
	free(dlst);
	dlst = NULL;
}

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	**p_eye;
	t_dlist	*eye;

	if (!dlst)
		return ;
	p_eye = dlst;
	while (*p_eye != NULL)
	{
		eye = (*p_eye)->next;
		ft_dlstdelone(*p_eye, del);
		(*p_eye) = eye;
	}
	p_eye = dlst;
	while (*p_eye != NULL)
	{
		eye = (*p_eye)->prev;
		ft_dlstdelone(*p_eye, del);
		(*p_eye) = eye;
	}
	dlst = NULL;
}

void	ft_dlstremove(t_dlist **alst_from, t_dlist *target, void (*del)(void*))
{
	if (!*alst_from || !target)
		return ;
	if (target == *alst_from)
	{
		if (target -> next)
			*alst_from = target -> next;
		else if (target -> prev)
			*alst_from = target -> prev;
		ft_dlstdelone(target, del);
	}
	else
	{
		if (target -> next)
			target -> next -> prev = target -> prev;
		if (target -> prev)
			target -> prev -> next = target -> next;
		ft_dlstdelone(target, del);
	}
}
