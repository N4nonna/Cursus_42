/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:34:02 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/20 15:58:17 by mescoda          ###   ########.fr       */
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
	long	nbr;
	int		ret;

	nbr = n;
	if (n < 0)
	{
		ret += write(1, '-', 1);
		nbr = -n;
	}
	ret += ft_intlen((unsigned int *)nbr, 10);
	if (nbr > 10)
		ft_putnbr(nbr / 10);
	ft_putchar_fd((nbr % 10 + '0'), 1);
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
