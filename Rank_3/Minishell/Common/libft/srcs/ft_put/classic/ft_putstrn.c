/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:28:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/01 12:27:40 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstrn(t_cchar *s, size_t n)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strnlen(s, n));
}

void	ft_putstrn_fd(t_cchar *s, size_t n, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strnlen(s, n));
}

size_t	ft_putrsstrn(t_cchar *s, size_t n)
{
	if (s == NULL)
		return (0);
	return (write(1, s, ft_strnlen(s, n)));
}

size_t	ft_putrsstrn_fd(t_cchar *s, size_t n, int fd)
{
	if (s == NULL)
		return (0);
	return (write(fd, s, ft_strnlen(s, n)));
}
