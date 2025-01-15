/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdlst_def.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:09:56 by mby               #+#    #+#             */
/*   Updated: 2024/04/08 12:49:27 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putdlst_def(t_dlist *dlst, void (*f)(void*, t_cchar*))
{
	size_t	i;

	if (!f)
		return ;
	i = 0;
	ft_putstr("\nStart dlst\n");
	while (dlst)
	{
		ft_putuns(i);
		ft_putstr(" : ");
		f(dlst -> content, B_TEN);
		ft_putstr("\n");
		i++;
		dlst = dlst -> next;
	}
	ft_putstr("End dlst\n");
}

void	ft_putdlst_fd_def(t_dlist *dlst, int fd, \
	void (*f)(void*, t_cchar*, int))
{
	size_t	i;

	if (!f)
		return ;
	i = 0;
	ft_putstr_fd("\nStart dlst\n", fd);
	while (dlst)
	{
		ft_putuns_fd(i, fd);
		ft_putstr_fd(" : ", fd);
		f(dlst -> content, B_TEN, fd);
		ft_putstr_fd("\n", fd);
		i++;
		dlst = dlst -> next;
	}
	ft_putstr_fd("End dlst\n", fd);
}

void	ft_putdlstr_def(t_dlist *dlst, void (*f)(void*, t_cchar*))
{
	size_t	i;

	if (!f)
		return ;
	dlst = ft_dlstlast(dlst);
	i = ft_dlstsize_total(dlst);
	ft_putstr("\nStart dlst\n");
	while (dlst)
	{
		ft_putuns(i);
		ft_putstr(" : ");
		f(dlst -> content, B_TEN);
		ft_putstr("\n");
		i--;
		dlst = dlst -> prev;
	}
	ft_putstr("End dlst\n");
}

void	ft_putdlstr_fd_def(t_dlist *dlst, int fd, \
	void (*f)(void*, t_cchar*, int))
{
	size_t	i;

	if (!f)
		return ;
	dlst = ft_dlstlast(dlst);
	i = ft_dlstsize_total(dlst);
	ft_putstr_fd("\nStart dlst\n", fd);
	while (dlst)
	{
		ft_putuns_fd(i, fd);
		ft_putstr_fd(" : ", fd);
		f(dlst -> content, B_TEN, fd);
		ft_putstr_fd("\n", fd);
		i--;
		dlst = dlst -> prev;
	}
	ft_putstr_fd("End dlst\n", fd);
}
