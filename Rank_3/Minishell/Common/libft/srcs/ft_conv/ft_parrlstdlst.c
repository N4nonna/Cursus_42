/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrtolst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 02:26:31 by mby               #+#    #+#             */
/*   Updated: 2024/03/01 10:26:09 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_parrtolst(void **arr, size_t n, void (*del)(void *))
{
	t_list	*new_start;
	t_list	*eye_new;
	size_t	i;

	if (!arr || !n)
		return (NULL);
	i = 0;
	eye_new = ft_lstnew(arr[i]);
	if (!eye_new)
		ft_lstclear(&new_start, del);
	new_start = eye_new;
	i++;
	while (i < n)
	{
		eye_new = ft_lstnew(arr[i]);
		if (!eye_new)
			ft_lstclear(&new_start, del);
		ft_lstadd_back(&new_start, eye_new);
		i++;
	}
	return (new_start);
}

t_dlist	*ft_parrtodlst(void **arr, size_t n, void (*del)(void *))
{
	t_dlist	*new_start;
	t_dlist	*eye_new;
	size_t	i;

	if (!arr || !n)
		return (NULL);
	i = 0;
	eye_new = ft_dlstnew(arr[i]);
	new_start = eye_new;
	i++;
	while (i < n)
	{
		eye_new = ft_dlstnew(arr[i]);
		if (!eye_new)
			ft_dlstclear(&new_start, del);
		ft_dlstadd_back(&new_start, eye_new);
		i++;
	}
	return (new_start);
}

void	**ft_lsttoparr(t_list *lst)
{
	void	**arr;
	t_list	*eye;
	size_t	i;
	size_t	n;

	if (!lst)
		return (NULL);
	i = 0;
	n = ft_lstsize(lst);
	arr = (void **)ft_calloc(n, sizeof(void *));
	if (!arr)
		return (NULL);
	eye = lst;
	while (i < n)
	{
		arr[i] = eye -> content;
		eye = eye -> next;
		i++;
	}
	return (arr);
}

void	**ft_dlsttoparr(t_dlist *dlst)
{
	void	**arr;
	t_dlist	*eye;
	size_t	i;
	size_t	n;

	if (!dlst)
		return (NULL);
	i = 0;
	n = ft_dlstsize_total(dlst);
	arr = (void **)ft_calloc(n, sizeof(void *));
	if (!arr)
		return (NULL);
	eye = ft_dlstfirst(dlst);
	while (i < n)
	{
		arr[i] = eye -> content;
		eye = eye -> next;
		i++;
	}
	return (arr);
}
