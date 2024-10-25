/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:52:14 by mby               #+#    #+#             */
/*   Updated: 2024/03/05 13:26:48 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_bestest_two(int a, int b, int (*f)(int, int ))
{
	if (f(a, b))
		return (b);
	return (a);
}

int	ft_bestest_intarr(int *arr, size_t n, int (*f)(int, int))
{
	size_t	i;
	int		ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = arr[0];
	while (i < n)
	{
		ret = ft_bestest_two(ret, arr[i], f);
		i++;
	}
	return (ret);
}

size_t	ft_bestest_arr_ind(int *arr, size_t n, int (*f)(int, int))
{
	size_t	i;
	int		bestest;
	size_t	ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = arr[0];
	bestest = arr[0];
	while (i < n)
	{
		if (!f(bestest, arr[i]))
		{
			bestest = arr[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
