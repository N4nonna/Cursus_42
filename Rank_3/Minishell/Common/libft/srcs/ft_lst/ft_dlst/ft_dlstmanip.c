/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmanip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:35:28 by mby               #+#    #+#             */
/*   Updated: 2024/06/03 14:03:51 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstsortf(t_dlist *dlst, int (*f)(void *, void *))
{
	t_dlist	*to_switch;

	if (!f || !dlst)
		return ;
	dlst = ft_dlstfirst(dlst);
	while (dlst != NULL)
	{
		to_switch = ft_dlstworstest(dlst, f);
		ft_dlstswitch(&dlst, dlst, to_switch);
		dlst = to_switch->next;
	}
}

static void	ftu_dlstswitch_contact(t_dlist **adlst,
	t_dlist *dlst1, t_dlist *dlst2)
{
	if (dlst1->prev)
		dlst1->prev->next = dlst2;
	if (dlst2->next)
		dlst2->next->prev = dlst1;
	dlst1->next = dlst2->next;
	dlst2->prev = dlst1->prev;
	dlst2->next = dlst1;
	dlst1->prev = dlst2;
	if (*adlst == dlst1)
		*adlst = dlst2;
	else if (*adlst == dlst2)
		*adlst = dlst1;
}

void	ft_dlstswitch(t_dlist **adlst, t_dlist *dlst1, t_dlist *dlst2)
{
	t_dlist	*prevt;
	t_dlist	*nextt;

	if (!adlst || !dlst1 || !dlst2 || dlst1 == dlst2)
		return ;
	if (dlst1->next == dlst2 || dlst1->prev == dlst2)
	{
		ftu_dlstswitch_contact(adlst, dlst1, dlst2);
		return ;
	}
	prevt = dlst1->prev;
	nextt = dlst1->next;
	(dlst1->prev)->next = dlst2;
	(dlst1->next)->prev = dlst2;
	(dlst2->prev)->next = dlst1;
	(dlst2->next)->prev = dlst1;
	dlst1->next = dlst2->next ;
	dlst1->prev = dlst2->prev ;
	dlst2->next = nextt;
	dlst2->prev = prevt;
	if (*adlst == dlst1)
		*adlst = dlst2;
	else if (*adlst == dlst2)
		*adlst = dlst1;
}

t_dlist	*ft_dlstworstest(t_dlist *dlst, int (*f)(void *, void *))
{
	t_dlist	*ret;

	if (!dlst || !f)
		return (NULL);
	dlst = ft_dlstfirst(dlst);
	ret = dlst;
	while (dlst)
	{
		ret = ft_worstestdlst_two(ret, dlst, f);
		dlst = dlst->next;
	}
	return (ret);
}

t_dlist	*ft_dlstbestest(t_dlist *dlst, int (*f)(void *, void *))
{
	t_dlist	*ret;

	if (!dlst || !f)
		return (NULL);
	dlst = ft_dlstfirst(dlst);
	ret = dlst;
	while (dlst)
	{
		ret = ft_bestestdlst_two(ret, dlst, f);
		dlst = dlst->next;
	}
	return (ret);
}
