/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:07:54 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/05 13:30:49 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstdup(t_list *lst, void (*del)(void *))
{
	t_list	*eye;
	t_list	*new_start;
	t_list	*eye_new;

	if (!lst)
		return (NULL);
	eye = lst;
	eye_new = ft_lstnew(eye -> content);
	new_start = eye_new;
	eye = eye->next;
	while (eye != NULL)
	{
		eye_new = ft_lstnew(eye->content);
		if (!eye_new)
			ft_lstclear(&new_start, del);
		ft_lstadd_back(&new_start, eye_new);
		eye = eye->next;
	}
	return (new_start);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*eye;
	t_list	*new_start;
	t_list	*eye_new;

	if (!lst || !f)
		return (NULL);
	eye = lst;
	eye_new = ft_lstnew(f(eye -> content));
	new_start = eye_new;
	eye = eye->next;
	while (eye != NULL)
	{
		eye_new = ft_lstnew(f(eye->content));
		if (!eye_new)
			ft_lstclear(&new_start, del);
		ft_lstadd_back(&new_start, eye_new);
		eye = eye->next;
	}
	return (new_start);
}
