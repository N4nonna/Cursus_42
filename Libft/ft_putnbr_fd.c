/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:21:57 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 15:24:25 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	i;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		i = -nb;
	}
	else
	{
		i = nb;
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		i %= 10;
	}
	ft_putchar_fd(i + '0', fd);
}
