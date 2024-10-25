/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:29:33 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/27 17:42:50 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putuns(t_uns n)
{
	if (n > 9)
	{
		ft_putuns(n / 10);
		ft_putuns(n % 10);
	}
	else
		ft_putchar('0' + n);
}

void	ft_putuns_fd(t_uns n, int fd)
{
	if (n > 9)
	{
		ft_putuns_fd(n / 10, fd);
		ft_putuns_fd(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

size_t	ft_putrsuns(t_uns n)
{
	size_t	ret;

	ret = 0;
	if (n > 9)
	{
		ret += ft_putrsuns(n / 10);
		ret += ft_putrsuns(n % 10);
	}
	else
		return (ft_putrschar('0' + n));
	return (ret);
}

size_t	ft_putrsuns_fd(t_uns n, int fd)
{
	size_t	ret;

	ret = 0;
	if (n > 9)
	{
		ret += ft_putrsuns_fd(n / 10, fd);
		ret += ft_putrsuns_fd(n % 10, fd);
	}
	else
		return (ft_putrschar_fd('0' + n, fd));
	return (ret);
}
