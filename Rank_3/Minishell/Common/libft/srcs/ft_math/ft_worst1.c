/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math08.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:22:40 by mby               #+#    #+#             */
/*   Updated: 2024/02/27 18:02:41 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_worstest_two(int a, int b, int (*f)(int, int ))
{
	if (f(a, b))
		return (a);
	return (b);
}

int	ft_worstest_intarr(int *arr, size_t n, int (*f)(int, int))
{
	size_t	i;
	int		ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = arr[0];
	while (i < n)
	{
		ret = ft_worstest_two(ret, arr[i], f);
		i++;
	}
	return (ret);
}

size_t	ft_worstest_intarr_ind(int *arr, size_t n, int (*f)(int, int))
{
	size_t	i;
	int		worstest;
	size_t	ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = 0;
	worstest = arr[0];
	while (i < n)
	{
		if (f(worstest, arr[i]))
		{
			worstest = arr[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
