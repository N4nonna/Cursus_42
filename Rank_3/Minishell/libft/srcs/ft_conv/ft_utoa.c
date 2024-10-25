/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 04:07:48 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/05 13:12:48 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_utoa(t_uns n)
{
	char	*res;
	size_t	i;

	i = ft_sizeinbase_uns(n, 10);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (!n)
		res[0] = '0';
	while (n)
	{
		res[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (res);
}

char	*ft_utoa_base(t_uns n, t_cchar *base)
{
	char	*res;
	size_t	len_base;
	size_t	i;

	if (!ft_base_valid(base))
		return (NULL);
	len_base = ft_strlen(base);
	i = ft_sizeinbase_uns(n, len_base);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (!n)
		res[0] = '0';
	while (n)
	{
		res[i - 1] = base[n % len_base];
		n = n / len_base;
		i--;
	}
	return (res);
}

char	*ft_llutoa(t_lluns n)
{
	char	*res;
	size_t	i;

	i = ft_sizeinbase_lluns(n, 10);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (!n)
		res[0] = '0';
	while (n)
	{
		res[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (res);
}

char	*ft_llutoa_base(t_lluns n, t_cchar *base)
{
	char	*res;
	size_t	len_base;
	size_t	i;

	if (!ft_base_valid(base))
		return (NULL);
	len_base = ft_strlen(base);
	i = ft_sizeinbase_lluns(n, len_base);
	res = (char *)ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (!n)
		res[0] = '0';
	while (n)
	{
		res[i - 1] = base[n % len_base];
		n = n / len_base;
		i--;
	}
	return (res);
}
