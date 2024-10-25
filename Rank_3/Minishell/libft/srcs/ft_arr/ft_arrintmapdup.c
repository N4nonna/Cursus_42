/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrintmapdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:40:30 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/05 14:12:48 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	*ft_arrintdup(int *arr, size_t n)
{
	int		*res;
	size_t	i;

	if (!arr)
		return (NULL);
	res = (int *)ft_calloc(n, sizeof(int));
	if (res == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = arr[i];
		i++;
	}
	return (res);
}

int	*ft_arrintmap(int *arr, size_t n, void (*f)(size_t, int*))
{
	int		*res;
	size_t	i;

	if (!arr || !f)
		return (NULL);
	res = (int *)ft_calloc(n, sizeof(int));
	if (res == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = arr[i];
		f(i, &res[i]);
		i++;
	}
	return (res);
}
