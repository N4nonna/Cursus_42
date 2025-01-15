/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/27 17:56:11 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n == INT_MIN)
		return (ft_putuns(((t_uns)INT_MAX) + 1));
	ft_putuns((t_uns)ft_abs(n));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == INT_MIN)
		return (ft_putuns_fd(((t_uns)INT_MAX) + 1, fd));
	ft_putuns_fd((t_uns)ft_abs(n), fd);
}

size_t	ft_putrsnbr(int n)
{
	size_t	ret;

	ret = 0;
	if (n < 0)
		ret += ft_putrschar('-');
	if (n == INT_MIN)
		return (ret + ft_putrsuns(((t_uns)INT_MAX) + 1));
	return (ret + ft_putrsuns((t_uns)ft_abs(n)));
}

size_t	ft_putrsnbr_fd(int n, int fd)
{
	size_t	ret;

	ret = 0;
	if (n < 0)
		ret += ft_putrschar_fd('-', fd);
	if (n == INT_MIN)
		return (ret + ft_putrsuns_fd(((t_uns)INT_MAX) + 1, fd));
	return (ret + ft_putrsuns_fd((t_uns)ft_abs(n), fd));
}
