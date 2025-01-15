/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_def.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:10:01 by mby               #+#    #+#             */
/*   Updated: 2024/03/06 17:05:43 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putlst_def(t_list *lst, void (*f)(void*, t_cchar*))
{
	size_t	i;

	if (!f)
		return ;
	i = 0;
	ft_putstr("\nStart lst\n");
	while (lst)
	{
		ft_putuns(i);
		ft_putstr(" : ");
		f((lst -> content), "0123456789");
		ft_putstr("\n");
		i++;
		lst = lst -> next;
	}
	ft_putstr("End lst\n");
}

void	ft_putlst_fd_def(t_list *lst, int fd, void (*f)(void*, t_cchar*, int))
{
	size_t	i;

	if (!f)
		return ;
	i = 0;
	ft_putstr_fd("\nStart lst\n", fd);
	while (lst)
	{
		ft_putuns_fd(i, fd);
		ft_putstr_fd(" : ", fd);
		f((lst -> content), "0123456789", fd);
		ft_putstr_fd("\n", fd);
		i++;
		lst = lst -> next;
	}
	ft_putstr_fd("End lst\n", fd);
}
