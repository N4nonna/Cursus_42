/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:18:14 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/05 13:42:39 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new -> next = *alst;
	*alst = new;
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*eye;

	if (!alst || !new)
		return ;
	eye = *alst;
	if (!*alst)
		*alst = new;
	else
	{
		while (eye -> next != NULL)
			eye = eye -> next;
		eye -> next = new;
	}
}
