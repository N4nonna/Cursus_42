/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:32:07 by mby               #+#    #+#             */
/*   Updated: 2024/03/04 14:56:17 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_smaller_equal(int a, int b)
{
	return (a <= b);
}

int	ft_smaller_strict(int a, int b)
{
	return (a < b);
}

int	ft_smallest_two(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_smallest_intarr(int *arr, size_t n)
{
	size_t	i;
	int		ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = arr[0];
	while (i < n)
	{
		ret = ft_smallest_two(ret, arr[i]);
		i++;
	}
	return (ret);
}

size_t	ft_smallest_intarr_ind(int *arr, size_t n)
{
	size_t	i;
	int		smallest;
	size_t	ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = 0;
	smallest = arr[0];
	while (i < n)
	{
		if (!ft_smaller_strict(smallest, arr[i]))
		{
			smallest = arr[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
