/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:41:57 by mby               #+#    #+#             */
/*   Updated: 2024/03/04 14:01:06 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ftu_lstswitch_first(t_list **alst, t_list *lst1, t_list *lst2);

void	ft_lstswitch(t_list **alst, t_list *lst1, t_list *lst2)
{
	t_list	*prev1;
	t_list	*prev2;
	t_list	*next1;
	t_list	*next2;

	if (!alst || !lst1 || !lst2)
		return ;
	if (lst1 == lst2)
		return ;
	if (lst1 == *alst || lst2 == *alst)
	{
		ftu_lstswitch_first(alst, lst1, lst2);
		return ;
	}
	prev1 = ft_lstprev(*alst, lst1);
	prev2 = ft_lstprev(*alst, lst2);
	next1 = lst1 -> next;
	next2 = lst2 -> next;
	prev1 -> next = lst2;
	prev2 -> next = lst1;
	lst1 -> next = next2;
	lst2 -> next = next1;
}

t_list	*ft_lstbestest(t_list *lst, int (*f)(void *, void *))
{
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	ret = lst;
	while (lst)
	{
		ret = ft_bestestlst_two(ret, lst, f);
		lst = lst -> next;
	}
	return (ret);
}

t_list	*ft_lstworstest(t_list *lst, int (*f)(void *, void *))
{
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	ret = lst;
	while (lst)
	{
		ret = ft_worstestlst_two(ret, lst, f);
		lst = lst -> next;
	}
	return (ret);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

static void	ftu_lstswitch_first(t_list **alst, t_list *lst1, t_list *lst2)
{
	t_list	*temp;

	if (*alst == lst1)
	{
		temp = ft_lstprev(*alst, lst2);
		*alst = lst2;
		temp -> next = lst1;
		temp = lst2 -> next;
		lst2 -> next = lst1 -> next;
		lst1 -> next = temp;
	}
	if (*alst == lst2)
	{
		temp = ft_lstprev(*alst, lst2);
		*alst = lst2;
		temp -> next = lst1;
		temp = lst2 -> next;
		lst2 -> next = lst1 -> next;
		lst1 -> next = temp;
	}
}
