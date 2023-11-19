/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:33:55 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/19 15:10:15 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		counter;
	int		buff_i;
	char	buffer[BUFF_SIZE];

	counter = 0;
	buff_i = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			counter += wich_tag(arg, buffer[], buff_i, format);
		}
		else
			counter += no_tag(arg, buffer[], buff_i, format);
		format++;
	}
	print_buffer(buffer, &buff_i);
	counter += buff_i;
	va_end(arg);
	return (counter);
}
