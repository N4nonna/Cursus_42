/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexnintarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:46:34 by mby               #+#    #+#             */
/*   Updated: 2024/03/10 15:33:07 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_lint	ft_indexnintarr(int *arr, size_t n, int nb)
{
	t_lint	i;

	if (!arr)
		return (-2);
	i = 0;
	while (i < (t_lint)n)
	{
		if (arr[i] != nb)
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexnintarr_set(int *arr, size_t na, int *set, size_t ns)
{
	t_lint	i;

	if (!arr || !set)
		return (-2);
	i = 0;
	while (i < (t_lint)na)
	{
		if (!ft_iisinintarr(arr[i], set, ns))
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexnllintarr(t_llint *arr, size_t n, t_llint nb)
{
	t_lint	i;

	if (!arr)
		return (-2);
	i = 0;
	while (i < (t_lint)n)
	{
		if (arr[i] != nb)
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexnllintarr_set(t_llint *arr, size_t na, t_llint *set, size_t ns)
{
	t_lint	i;

	if (!arr || !set)
		return (-2);
	i = 0;
	while (i < (t_lint)na)
	{
		if (!ft_lliisinllintarr(arr[i], set, ns))
			return (i);
		i++;
	}
	return (-1);
}
