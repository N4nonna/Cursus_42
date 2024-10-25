/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:51:50 by mby               #+#    #+#             */
/*   Updated: 2024/03/28 22:24:26 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	new = ft_calloc(1, sizeof(t_dlist));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

void	ft_dlstadd_front(t_dlist **adlst, t_dlist *new)
{
	t_dlist	*eye;

	if (!new)
		return ;
	eye = *adlst;
	if (!*adlst)
	{
		*adlst = new;
		new -> next = NULL;
	}
	else
	{
		while (eye -> prev != NULL)
			eye = eye -> prev;
		eye -> prev = new;
		new -> next = eye;
	}
}

void	ft_dlstadd_back(t_dlist **adlst, t_dlist *new)
{
	t_dlist	*eye;

	if (!new)
		return ;
	eye = *adlst;
	if (!*adlst)
	{
		*adlst = new;
		new -> prev = NULL;
	}
	else
	{
		while (eye -> next != NULL)
			eye = eye -> next;
		eye -> next = new;
		new -> prev = eye;
	}
}
