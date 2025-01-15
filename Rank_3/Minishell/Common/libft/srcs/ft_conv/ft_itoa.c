/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 04:07:48 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/13 21:21:24 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	t_uns	nbr;
	size_t	i;
	char	*res;

	i = ft_sizeinbase_int(n, 10);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	nbr = ft_touns(n);
	if (!n)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (nbr)
	{
		res[i - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (res);
}

char	*ft_itoa_base(int n, t_cchar *base)
{
	char	*res;
	size_t	len_base;
	t_uns	nbr;
	size_t	i;

	if (!ft_base_valid(base))
		return (NULL);
	len_base = ft_strlen(base);
	i = ft_sizeinbase_int(n, len_base);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	nbr = ft_touns(n);
	if (!n)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (nbr)
	{
		res[i - 1] = base[nbr % len_base];
		nbr = nbr / len_base;
		i--;
	}
	return (res);
}

char	*ft_lltoa(t_llint n)
{
	char	*res;
	t_lluns	nbr;
	size_t	i;

	i = ft_sizeinbase_ll(n, 10);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	nbr = ft_tolluns(n);
	if (!n)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (nbr)
	{
		res[i - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (res);
}

char	*ft_lltoa_base(t_llint n, t_cchar *base)
{
	char	*res;
	size_t	len_base;
	t_lluns	nbr;
	size_t	i;

	if (!ft_base_valid(base))
		return (NULL);
	len_base = ft_strlen(base);
	i = ft_sizeinbase_ll(n, len_base);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	nbr = ft_tolluns(n);
	if (!n)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (nbr)
	{
		res[i - 1] = base[nbr % len_base];
		nbr = nbr / len_base;
		i--;
	}
	return (res);
}
