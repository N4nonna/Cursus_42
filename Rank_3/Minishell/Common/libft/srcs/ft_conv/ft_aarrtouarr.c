/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aarrtouarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:48:24 by mby               #+#    #+#             */
/*   Updated: 2024/03/05 14:16:23 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_uns	*ft_aarrtouarr(t_cchar **strarr, size_t n)
{
	t_uns	*ret;
	size_t	i;

	if (!strarr)
		return (NULL);
	ret = (t_uns *)ft_calloc(n, sizeof(t_uns));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = ft_atou(strarr[i]);
		i++;
	}
	return (ret);
}

t_uns	*ft_aarrtouarr_base(t_cchar **strarr, size_t n, t_cchar *base)
{
	t_uns	*ret;
	size_t	i;

	if (!strarr)
		return (NULL);
	ret = (t_uns *)ft_calloc(n, sizeof(t_uns));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = ft_atou_base(strarr[i], base);
		i++;
	}
	return (ret);
}

char	**ft_uarrtoaarr(t_uns *arr, size_t na)
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
		ret[i] = ft_utoa(arr[i]);
		i++;
	}
	return (ret);
}

char	**ft_uarrtoaarr_base(t_uns *arr, size_t na, t_cchar *base)
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
		ret[i] = ft_utoa_base(arr[i], base);
		i++;
	}
	return (ret);
}
