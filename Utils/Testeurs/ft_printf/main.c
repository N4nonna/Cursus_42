/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:12:11 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/22 16:37:28 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int main ()
{
	int	c = 'A';
	char	*s = NULL;
	int		d = 100;
	int		i = 0;
	unsigned int	u = -123456789;
	unsigned int	x = '^';
	unsigned int	X = 94;
	ft_printf("ft_printf : %c, %s, %d%%, %i, %u, %x, %X\n",c , s, d, i, u, x, X);
	printf("printf : %c, %s, %d%%, %i, %u, %x, %X",c , s, d, i, u, x, X);
	return 0;
}