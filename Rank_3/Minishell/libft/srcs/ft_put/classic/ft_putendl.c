/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:53:23 by mby               #+#    #+#             */
/*   Updated: 2024/03/05 13:49:43 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl(t_cchar *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

void	ft_putendl_fd(t_cchar *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

size_t	ft_putrsendl(t_cchar *s)
{
	return (ft_putrsstr(s) + write(1, "\n", 1));
}

size_t	ft_putrsendl_fd(t_cchar *s, int fd)
{
	return (ft_putrsstr_fd(s, fd) + write(fd, "\n", 1));
}
