/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/04 14:42:53 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbrll(t_llint n)
{
	if (n < 0)
		ft_putchar('-');
	if (n == LLONG_MIN)
		return (ft_putlluns(((t_uns)LLONG_MIN) + 1));
	ft_putlluns((t_uns)ft_absll(n));
}

void	ft_putnbrll_fd(t_llint n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == LLONG_MIN)
		return (ft_putlluns_fd(((t_uns)LLONG_MIN) + 1, fd));
	ft_putlluns_fd((t_uns)ft_absll(n), fd);
}

size_t	ft_putrsnbrll(t_llint n)
{
	size_t	ret;

	ret = 0;
	if (n < 0)
		ret += ft_putrschar('-');
	if (n == LLONG_MIN)
		return (ret + ft_putrsunsll(((t_lluns)INT_MAX) + 1));
	return (ret + ft_putrsunsll((t_lluns)ft_absll(n)));
}

size_t	ft_putrsnbrll_fd(t_llint n, int fd)
{
	size_t	ret;

	ret = 0;
	if (n < 0)
		ret += ft_putrschar_fd('-', fd);
	if (n == LLONG_MIN)
		return (ret + ft_putrsunsll_fd(((t_lluns)INT_MAX) + 1, fd));
	return (ret + ft_putrsunsll_fd((t_lluns)ft_absll(n), fd));
}
