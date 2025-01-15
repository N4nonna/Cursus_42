/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/04 14:43:02 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putlluns(t_lluns n)
{
	if (n > 9)
	{
		ft_putlluns(n / 10);
		ft_putlluns(n % 10);
	}
	else
		ft_putchar('0' + n);
}

void	ft_putlluns_fd(t_lluns n, int fd)
{
	if (n > 9)
	{
		ft_putlluns_fd(n / 10, fd);
		ft_putlluns_fd(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

size_t	ft_putrsunsll(t_lluns n)
{
	size_t	ret;

	ret = 0;
	if (n > 9)
	{
		ret += ft_putrsunsll(n / 10);
		ret += ft_putrsunsll(n % 10);
	}
	else
		return (ft_putrschar('0' + n));
	return (ret);
}

size_t	ft_putrsunsll_fd(t_lluns n, int fd)
{
	size_t	ret;

	ret = 0;
	if (n > 9)
	{
		ft_putrsunsll_fd(n / 10, fd);
		ft_putrsunsll_fd(n % 10, fd);
	}
	else
		return (ft_putrschar_fd('0' + n, fd));
	return (ret);
}
