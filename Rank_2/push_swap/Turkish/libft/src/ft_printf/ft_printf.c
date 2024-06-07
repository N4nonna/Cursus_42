/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:33:55 by mescoda           #+#    #+#             */
/*   Updated: 2024/02/01 12:13:39 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wich_tag(va_list arg, const char format)
{
	int		counter;
	char	*base;

	counter = 0;
	base = "0123456789";
	if (format == '%')
		counter += ft_printpercent();
	else if (format == 'c')
		counter += ft_printch(va_arg(arg, int));
	else if (format == 's')
		counter += ft_printstr(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		counter += ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		counter += ft_putnbr_base(va_arg(arg, unsigned int), format, base);
	else if (format == 'x' || format == 'X')
		counter += ft_putnbr_base(va_arg(arg, unsigned int), format, base);
	else if (format == 'p')
		counter += ft_printpoint(va_arg(arg, unsigned long long));
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += wich_tag(arg, format[i + 1]);
			i++;
		}
		else
			counter += ft_printch(format[i]);
		i++;
	}
	va_end(arg);
	return (counter);
}

/*int	main()
{
	int	c = 'A';
	char	*s = "Bravo !!!";
	int		d = 100;
	int		i = -250;
	unsigned int	u = 123456789;
	unsigned int	x = 94;
	unsigned int	X = 94;
	ft_printf("%c, %s, %d%%, %i, %u, %x, %X",c , s, d, i, u, x, X);
	return 0;
}*/