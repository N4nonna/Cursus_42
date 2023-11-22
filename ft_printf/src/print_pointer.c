/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:34:51 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/22 16:11:52 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_putptr(unsigned long long int n)
{
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_printpoint(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		counter += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putptr(ptr);
		counter += ft_ptrlen(ptr) + 2;
	}
	return (counter);
}
