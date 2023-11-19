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

void	print_buffer(char buffer[], int *buff_i)
{
	int	i;

	i = 0;
	if (*buff_i > 0)
	{
		while (i < *buff_i)
		{
			ft_putchar(buffer[i])
			i++;
		}
	}
	*buff_i = 0;
}

int	print_int10(int value)
{
	char	buffer[32];
	int		printed;
	int		i;
	int		j;

	printed = 0;
	i = 0;
	if (value < 0)
	{
		ft_putchar('-');
		printed++;
		value = -value;
	}
	while (value > 0)
	{
		buffer[i++] = '0' + (value % 10);
		value /= 10;
		printed++;
	}
	j = i - 1;
	while (j >= 0)
		ft_putchar(buffer[j--]);
	return (printed);
}
