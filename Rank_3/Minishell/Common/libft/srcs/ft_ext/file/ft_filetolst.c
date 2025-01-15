/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetolst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:43:38 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/13 21:45:36 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_filetolst(int fd)
{
	t_list	*lst_start;
	t_list	*new;
	char	**addr_gnl;

	lst_start = NULL;
	addr_gnl = (char **)ft_calloc(1, sizeof(char *));
	if (!addr_gnl)
		return (NULL);
	while (ft_gnla(fd, addr_gnl))
	{
		new = ft_lstnew(*addr_gnl);
		ft_lstadd_back(&lst_start, new);
	}
	free(addr_gnl);
	return (lst_start);
}

t_dlist	*ft_filetodlst(int fd)
{
	t_dlist	*dlst_start;
	t_dlist	*new;
	char	**addr_gnl;

	dlst_start = NULL;
	addr_gnl = (char **)ft_calloc(1, sizeof(char *));
	if (!addr_gnl)
		return (NULL);
	while (ft_gnla(fd, addr_gnl))
	{
		new = ft_dlstnew(*addr_gnl);
		ft_dlstadd_back(&dlst_start, new);
	}
	free(addr_gnl);
	return (dlst_start);
}
