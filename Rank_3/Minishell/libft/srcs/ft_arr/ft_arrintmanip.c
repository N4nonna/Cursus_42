/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrintmanip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:33:22 by mby               #+#    #+#             */
/*   Updated: 2024/06/05 13:01:41 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	*ft_arrintiter(int *arr, size_t n, void (*f)(size_t, int*))
{
	size_t	i;

	if (!arr || !f)
		return (NULL);
	i = 0;
	while (i < n)
	{
		f(i, &arr[i]);
		i++;
	}
	return (arr);
}

int	*ft_arrintrev(int *arr, size_t n)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (i < n / 2)
	{
		ft_switchint(&arr[i], &arr[n - i - 1]);
		i++;
	}
	return (arr);
}

int	*ft_arrintsort(int *arr, size_t n)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			ft_switchint(&arr[i], &arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

int	*ft_arrintsortf(int *arr, size_t n, int (*f)(int, int))
{
	int		next_index;
	size_t	i;

	if (!arr || !f)
		return (NULL);
	i = 0;
	while (i < n)
	{
		next_index = ft_worstest_intarr_ind(&arr[i + 1], n - i - 1, f);
		ft_switchint(&arr[i], &arr[next_index]);
		i++;
	}
	return (arr);
}

int	*ft_arrintrsortf(int *arr, size_t n, int (*f)(int, int))
{
	int		next_index;
	size_t	i;

	if (!arr || !f)
		return (NULL);
	i = 0;
	while (i < n)
	{
		next_index = ft_bestest_arr_ind(&arr[i + 1], n - i - 1, f);
		ft_switchint(&arr[i], &arr[next_index]);
		i++;
	}
	return (arr);
}
