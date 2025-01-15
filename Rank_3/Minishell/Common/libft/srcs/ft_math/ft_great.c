/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_great.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:51:56 by mby               #+#    #+#             */
/*   Updated: 2024/03/04 15:06:03 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_greater_equal(int a, int b)
{
	return (a >= b);
}

int	ft_greater_strict(int a, int b)
{
	return (a > b);
}

int	ft_greatest_two(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_greatest_set(int *arr, size_t n)
{
	size_t	i;
	int		ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = arr[0];
	while (i < n)
	{
		ret = ft_greatest_two(ret, arr[i]);
		i++;
	}
	return (ret);
}

size_t	ft_greatest_intarr_ind(int *arr, size_t n)
{
	size_t	i;
	int		greatest;
	size_t	ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = 0;
	greatest = arr[0];
	while (i < n)
	{
		if (!ft_greater_strict(greatest, arr[i]))
		{
			greatest = arr[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
