/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexparr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:46:34 by mby               #+#    #+#             */
/*   Updated: 2024/03/10 15:33:21 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_lint	ft_indexparr(t_cvoid **arr, size_t n, t_cvoid *p)
{
	t_lint	i;

	if (!arr)
		return (-2);
	i = 0;
	while (i < (t_lint)n)
	{
		if (arr[i] == p)
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexparr_set(t_cvoid **arr, size_t na, t_cvoid **set, size_t ns)
{
	t_lint	i;

	if (!arr || !set)
		return (-2);
	i = 0;
	while (i < (t_lint)na)
	{
		if (ft_pisinparr(arr[i], set, ns))
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexnparr(t_cvoid **arr, size_t n, t_cvoid *p)
{
	t_lint	i;

	if (!arr)
		return (-2);
	i = 0;
	while (i < (t_lint)n)
	{
		if (arr[i] != p)
			return (i);
		i++;
	}
	return (-1);
}

t_lint	ft_indexnparr_set(t_cvoid **arr, size_t na, t_cvoid **set, size_t ns)
{
	t_lint	i;

	if (!arr || !set)
		return (-2);
	i = 0;
	while (i < (t_lint)na)
	{
		if (!ft_pisinparr(arr[i], set, ns))
			return (i);
		i++;
	}
	return (-1);
}
