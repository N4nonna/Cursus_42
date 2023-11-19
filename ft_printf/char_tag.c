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

int	percent_tag(char buffer[], int *buff_i, int counter)
{
	buffer[buff_i++] = ('%');
	if (buff_i == BUFF_SIZE)
	{
		print_buffer(buffer, &buff_i);
		counter += buff_i;
	}
	return (counter);
}

int	c_tag(va_list arg, char buffer[], int *buff_i, int counter)
{
	char	ch;

	ch = va_arg(arg, int);
	buffer[buff_i++] = ch;
	if (buff_i == BUFF_SIZE)
	{
		print_buffer(buffer, &buff_i);
		counter += buff_i;
	}
	return (counter);
}

int	s_tag(va_list arg, char buffer[], int *buff_i, int counter)
{
	char	*s;

	*s = va_arg(arg, char *);
	while (*s)
	{
		buffer[buff_i++] = *s;
		s++;
		if (buff_i == BUFF_SIZE)
		{
			print_buffer(buffer, &buff_i);
			counter += buff_i;
		}
	}
	return (counter);
}
