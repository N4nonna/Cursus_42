/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:38:09 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/07 22:35:06 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	string;
	int	sign;

	string = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		string = string * 10 + (*str - '0');
		str++;
	}
	return (string * sign);
}

/*int	main(int ac, char **av)
{
    if (ac == 2)
	    printf("My atoi : %d, Real atoi : %d", ft_atoi(av[1]), atoi(av[1]));
}*/