/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:07 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/27 17:58:16 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putchar(t_cchar c)
{
	write(1, &c, 1);
}

void	ft_putchar_fd(t_cchar c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_putrschar_fd(t_cchar c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	ft_putrschar(t_cchar c)
{
	return (write(1, &c, 1));
}
