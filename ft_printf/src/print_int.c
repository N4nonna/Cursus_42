/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:34:02 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/22 16:11:46 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned int n, int size_base)
{
	size_t	len;

	len = 1;
	while (n / size_base > 0)
	{
		len++;
		n /= size_base;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	unsigned int	nbr;
	int				ret;

	nbr = n;
	ret = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		nbr = -n;
		ret += 1;
	}
	ret += ft_putnbr_base(nbr, 'd', "0123456789");
	return (ret);
}

int	ft_putnbr_base(unsigned int n, char c, char *base)
{
	size_t	size_base;
	int		ret;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	size_base = ft_strlen(base);
	ret = ft_intlen(n, size_base);
	if (n >= size_base)
	{
		ft_putnbr_base((n / size_base), c, base);
		ft_putnbr_base((n % size_base), c, base);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else if (n >= 10 && c == 'x')
			ft_putchar_fd((n - 10 + 'a'), 1);
		else if (n >= 10 && c == 'X')
			ft_putchar_fd((n - 10 + 'A'), 1);
	}
	return (ret);
}
