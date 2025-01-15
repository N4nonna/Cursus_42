/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/05 13:56:11 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_base(int n, t_cchar *base)
{
	if (!ft_base_valid(base))
		return ;
	if (n < 0)
		ft_putchar('-');
	if (n == INT_MIN)
		return (ft_putuns_base(((t_uns)INT_MAX) + 1, base));
	ft_putuns_base((t_uns)ft_abs(n), base);
}

void	ft_putnbr_base_fd(int n, t_cchar *base, int fd)
{
	if (!ft_base_valid(base))
		return ;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == INT_MIN)
		return (ft_putuns_base_fd(((t_uns)INT_MAX) + 1, base, fd));
	ft_putuns_base_fd((t_uns)ft_abs(n), base, fd);
}

size_t	ft_putrsnbr_base(int n, t_cchar *base)
{
	size_t	ret;

	if (!ft_base_valid(base))
		return (0);
	ret = 0;
	if (n < 0)
		ret += ft_putrschar('-');
	if (n == INT_MIN)
		return (ret + ft_putrsuns_base(((t_uns)INT_MAX) + 1, base));
	return (ret + ft_putrsuns_base((t_uns)ft_abs(n), base));
}

size_t	ft_putrsnbr_base_fd(int n, t_cchar *base, int fd)
{
	size_t	ret;

	if (!ft_base_valid(base))
		return (0);
	ret = 0;
	if (n < 0)
		ret += ft_putrschar_fd('-', fd);
	if (n == INT_MIN)
		return (ret + ft_putrsuns_base_fd(((t_uns)INT_MAX) + 1, base, fd));
	return (ret + ft_putrsuns_base_fd((t_uns)ft_abs(n), base, fd));
}
