/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcomp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:52:41 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/05 13:27:51 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_worstestlst_two(t_list *a, t_list *b, int (*f)(void *, void *))
{
	if (!f || !a || !b)
		return (NULL);
	if (f(a -> content, b -> content))
		return (a);
	return (b);
}

t_list	*ft_bestestlst_two(t_list *a, t_list *b, int (*f)(void *, void *))
{
	if (!f || !a || !b)
		return (NULL);
	if (f(a -> content, b -> content))
		return (b);
	return (a);
}

t_dlist	*ft_worstestdlst_two(t_dlist *a, t_dlist *b, int (*f)(void *, void *))
{
	if (!f || !a || !b)
		return (NULL);
	if (f(a -> content, b -> content))
		return (a);
	return (b);
}

t_dlist	*ft_bestestdlst_two(t_dlist *a, t_dlist *b, int (*f)(void *, void *))
{
	if (!f || !a || !b)
		return (NULL);
	if (f(a -> content, b -> content))
		return (b);
	return (a);
}
