/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrpmapdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:40:30 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/25 11:05:06 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	**ft_arrpdup(void **arr, size_t n)
{
	void	**res;
	size_t	i;

	if (!arr)
		return (NULL);
	res = (void **)ft_calloc(n, sizeof(void *));
	if (res == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = arr[i];
		if (!res[i])
			return (ft_freeparr(res, i), NULL);
		i++;
	}
	return (res);
}

void	**ft_arrpmap(void **arr, size_t n, void (*f)(size_t, void*))
{
	void	**res;
	size_t	i;

	if (!arr)
		return (NULL);
	res = (void **)ft_calloc(n, sizeof(void *));
	if (res == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = arr[i];
		if (!res[i])
			return (ft_freeparr(res, i), NULL);
		if (!f)
			f(i, res[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
