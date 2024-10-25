/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 02:26:31 by mby               #+#    #+#             */
/*   Updated: 2024/03/05 13:11:49 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist	*ft_lsttodlst(t_list *lst, void (*del)(void *))
{
	t_list	*eye;
	t_dlist	*new_start;
	t_dlist	*eye_new;

	if (!lst)
		return (NULL);
	eye = lst;
	eye_new = ft_dlstnew(eye -> content);
	if (!eye_new)
		ft_dlstdelone(eye_new, del);
	new_start = eye_new;
	eye = eye -> next;
	while (eye)
	{
		eye_new = ft_dlstnew(eye -> content);
		if (!eye_new)
			ft_dlstclear(&new_start, del);
		ft_dlstadd_back(&new_start, eye_new);
		eye = eye -> next;
	}
	return (new_start);
}

t_list	*ft_dlsttolst(t_dlist *dlst, void (*del)(void *))
{
	t_dlist	*eye;
	t_list	*new_start;
	t_list	*eye_new;

	if (!dlst)
		return (NULL);
	eye = ft_dlstfirst(dlst);
	eye_new = ft_lstnew(eye -> content);
	if (!eye_new)
		ft_lstdelone(eye_new, del);
	new_start = eye_new;
	eye = eye -> next;
	while (eye)
	{
		eye_new = ft_lstnew(eye -> content);
		if (!eye_new)
			ft_lstclear(&new_start, del);
		ft_lstadd_back(&new_start, eye_new);
		eye = eye -> next;
	}
	return (new_start);
}
