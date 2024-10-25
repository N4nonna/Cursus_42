/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aarrtoiarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:48:24 by mby               #+#    #+#             */
/*   Updated: 2024/03/01 12:25:59 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	*ft_aarrtoiarr(t_cchar **strarr, size_t n)
{
	int		*ret;
	size_t	i;

	if (!strarr)
		return (NULL);
	ret = (int *)ft_calloc(n, sizeof(int));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = ft_atoi(strarr[i]);
		i++;
	}
	return (ret);
}

char	**ft_iarrtoaarr(int *arr, size_t na)
{
	char	**ret;
	size_t	i;

	if (!arr)
		return (NULL);
	ret = (char **)ft_calloc(na, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < na)
	{
		ret[i] = ft_itoa(arr[i]);
		i++;
	}
	return (ret);
}

int	*ft_aarrtoiarr_base(t_cchar **strarr, size_t n, t_cchar *base)
{
	int		*ret;
	size_t	i;

	if (!strarr)
		return (NULL);
	ret = (int *)ft_calloc(n, sizeof(int));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = ft_atoi_base(strarr[i], base);
		i++;
	}
	return (ret);
}

char	**ft_iarrtoaarr_base(int *arr, size_t na, t_cchar *base)
{
	char	**ret;
	size_t	i;

	if (!arr)
		return (NULL);
	ret = (char **)ft_calloc(na, sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < na)
	{
		ret[i] = ft_itoa_base(arr[i], base);
		i++;
	}
	return (ret);
}
