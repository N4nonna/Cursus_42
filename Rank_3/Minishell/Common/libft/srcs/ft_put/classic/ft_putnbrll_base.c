/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrll_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/05 13:56:56 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbrll_base(t_llint n, t_cchar *base)
{
	if (!ft_base_valid(base))
		return ;
	if (n < 0)
		ft_putchar('-');
	if (n == LLONG_MIN)
		return (ft_putlluns_base(((t_uns)LLONG_MAX) + 1, base));
	ft_putlluns_base((t_uns)ft_absll(n), base);
}

void	ft_putnbrll_base_fd(t_llint n, t_cchar *base, int fd)
{
	if (!ft_base_valid(base))
		return ;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == LLONG_MIN)
		return (ft_putlluns_base_fd(((t_uns)LLONG_MAX) + 1, base, fd));
	ft_putlluns_base_fd((t_uns)ft_absll(n), base, fd);
}

size_t	ft_putrsnbrll_base(t_llint n, t_cchar *base)
{
	size_t	ret;

	if (!ft_base_valid(base))
		return (0);
	ret = 0;
	if (n < 0)
		ret += ft_putrschar('-');
	if (n == LLONG_MIN)
		return (ret + ft_putrslluns_base(((t_uns)LLONG_MAX) + 1, base));
	return (ret + ft_putrslluns_base((t_uns)ft_absll(n), base));
}

size_t	ft_putrsnbrll_base_fd(t_llint n, t_cchar *base, int fd)
{
	size_t	ret;

	if (!ft_base_valid(base))
		return (0);
	ret = 0;
	if (n < 0)
		ret += ft_putrschar_fd('-', fd);
	if (n == LLONG_MIN)
		return (ret + ft_putrslluns_base_fd(((t_uns)LLONG_MAX) + 1, base, fd));
	return (ret + ft_putrslluns_base_fd((t_uns)ft_absll(n), base, fd));
}
