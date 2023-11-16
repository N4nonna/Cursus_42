/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:44:23 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/16 17:36:30 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

static int	ft_len_itoa(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	if (!n)
		return (i + 1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char *) * (ft_len_itoa(n) + 1));
	if (!str)
		return (NULL);
	i = ft_len_itoa(n) - 1;
	str[ft_len_itoa(n)] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (!n)
	{
		str[i] = '0';
		return (str);
	}
	while (n != 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

// int main(int ac, char **av) {
//     printf("itoa = %s\n", ft_itoa(atoi(av[1])));
//     return(0);
// }
