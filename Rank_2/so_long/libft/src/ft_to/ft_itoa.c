/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:23:30 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 15:23:32 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_itoa(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_negandzero(int n, char *str, size_t len)
{
	if (n < 0)
		str[0] = '-';
	if (n == 0)
	{
		str[len] = '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	size_t			len;

	nb = (unsigned)n;
	len = ft_len_itoa(nb);
	if (n < 0)
	{
		nb = 0 -(unsigned)n;
		len = ft_len_itoa(nb) + 1;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0 || n < 0)
		ft_negandzero(n, str, len);
	if (n == 0)
		return (str);
	while (nb != 0)
	{
		str[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
