/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrtest1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:58 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/28 06:29:57 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_iisinintarr(int nb, int *intarr, size_t na)
{
	size_t	j;

	if (!intarr)
		return (0);
	j = 0;
	while (j < na)
	{
		if (intarr[j] == nb)
			return (1);
		j++;
	}
	return (0);
}

int	ft_isisinintarr(int *set, size_t ns, int *intarr, size_t na)
{
	size_t	j;

	if (!intarr || !set)
		return (0);
	j = 0;
	while (j < na)
	{
		if (ft_iisinintarr(intarr[j], set, ns))
			return (1);
		j++;
	}
	return (0);
}

int	ft_iisainintarr(int nb, int *intarr, size_t na)
{
	size_t	j;

	if (!intarr)
		return (0);
	j = 0;
	while (j < na)
	{
		if (intarr[j] != nb)
			return (0);
		j++;
	}
	return (1);
}

int	ft_isisainintarr(int *set, size_t ns, int *intarr, size_t na)
{
	size_t	j;

	if (!intarr || !set)
		return (0);
	j = 0;
	while (j < na)
	{
		if (!ft_iisinintarr(intarr[j], set, ns))
			return (0);
		j++;
	}
	return (1);
}

int	ft_intarrdoubles(int *intarr, size_t na)
{
	size_t	j;

	if (!intarr)
		return (0);
	j = 0;
	while (j < na)
	{
		if (ft_iisinintarr(intarr[j], &intarr[j + 1], na - j - 1))
			return (1);
		j++;
	}
	return (0);
}
