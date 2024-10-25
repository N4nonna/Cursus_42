/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmapdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:07:54 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/28 14:27:09 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist	*ft_dlstdup(t_dlist *dlst, void (*del)(void *))
{
	t_dlist	*eye;
	t_dlist	*new_start;
	t_dlist	*eye_new;

	if (!dlst)
		return (NULL);
	eye = dlst;
	eye_new = ft_dlstnew(eye -> content);
	new_start = eye_new;
	eye = eye->next;
	while (eye != NULL)
	{
		eye_new = ft_dlstnew(eye->content);
		if (!eye_new)
			ft_dlstclear(&new_start, del);
		ft_dlstadd_back(&new_start, eye_new);
		eye = eye->next;
	}
	return (new_start);
}

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*eye;
	t_dlist	*new_start;
	t_dlist	*eye_new;

	if (!dlst || !f)
		return (NULL);
	eye = dlst;
	eye_new = ft_dlstnew(f(eye -> content));
	new_start = eye_new;
	eye = eye->next;
	while (eye != NULL)
	{
		eye_new = ft_dlstnew(f(eye->content));
		if (!eye_new)
			ft_dlstclear(&new_start, del);
		ft_dlstadd_back(&new_start, eye_new);
		eye = eye->next;
	}
	return (new_start);
}

void	ft_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	if (!dlst || !f)
		return ;
	dlst = ft_dlstfirst(dlst);
	while (dlst != NULL)
	{
		f(dlst -> content);
		dlst = dlst -> next;
	}
}
