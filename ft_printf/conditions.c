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

int	wich_tag(va_list arg, char buffer[], int *buff_i, const char *format)
{
	int	counter;

	counter = 0;
	if (*format == '%')
		percent_tag(buffer, buff_i, counter);
	else if (*format == 'c')
		c_tag(arg, buffer, buff_i, counter);
	else if (*format == 's')
		s_tag(arg, buffer, buff_i, counter);
	else if (*format == 'd' || *format == 'i')
		d_or_i_tag(arg, counter);
	else if (*format == 'u')
		u_tag();
	else if (*format == 'x' || *format == 'X')
		x_tags();
	else if (*format == 'p')
		p_tag();
	return (counter);
}

int	no_tag(va_list arg, char buffer[], int *buff_i, const char *format)
{
	int	counter;

	counter = 0;
	buffer[buff_i++] = *format;
	if (buff_i == BUFF_SIZE)
	{
		print_buffer(buffer, &buff_i);
			counter += buff_i;
	}
	return (counter);
}
