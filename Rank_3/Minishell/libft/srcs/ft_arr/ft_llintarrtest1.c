/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llintarrtest1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:58 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/13 11:01:33 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lliisinllintarr(t_llint nb, t_llint *llintarr, size_t na)
{
	size_t	j;

	if (!llintarr)
		return (0);
	j = 0;
	while (j < na)
	{
		if (llintarr[j] == nb)
			return (1);
		j++;
	}
	return (0);
}

int	ft_llisisinllintarr(t_llint *set, size_t ns, t_llint *llintarr, size_t na)
{
	size_t	j;

	if (!llintarr || !set)
		return (0);
	j = 0;
	while (j < na)
	{
		if (ft_lliisinllintarr(llintarr[j], set, ns))
			return (1);
		j++;
	}
	return (0);
}

int	ft_lliisainllintarr(t_llint nb, t_llint *llintarr, size_t na)
{
	size_t	j;

	if (!llintarr)
		return (0);
	j = 0;
	while (j < na)
	{
		if (llintarr[j] != nb)
			return (0);
		j++;
	}
	return (1);
}

int	ft_llisisainllintarr(t_llint *set, size_t ns, t_llint *llintarr, size_t na)
{
	size_t	j;

	if (!llintarr || !set)
		return (0);
	j = 0;
	while (j < na)
	{
		if (!ft_lliisinllintarr(llintarr[j], set, ns))
			return (0);
		j++;
	}
	return (1);
}

int	ft_llintarrdoubles(t_llint *llintarr, size_t na)
{
	size_t	j;

	if (!llintarr)
		return (0);
	j = 0;
	while (j < na)
	{
		if (ft_lliisinllintarr(llintarr[j], &llintarr[j + 1], na - j))
			return (1);
		j++;
	}
	return (0);
}
