/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrtest1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:58 by mabonny-          #+#    #+#             */
/*   Updated: 2024/03/13 11:01:19 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_pisinparr(t_cvoid *p, t_cvoid **parr, size_t na)
{
	size_t	i;

	if (!parr)
		return (0);
	i = 0;
	while (i < na)
	{
		if (parr[i] == p)
			return (1);
		i++;
	}
	return (0);
}

int	ft_psisinparr(t_cvoid **parr, size_t na, t_cvoid **set, size_t ns)
{
	size_t	i;

	if (!parr || !set)
		return (0);
	i = 0;
	while (i < na)
	{
		if (ft_pisinparr(parr[i], set, ns))
			return (1);
		i++;
	}
	return (0);
}

int	ft_pisainparr(t_cvoid *p, t_cvoid **parr, size_t na)
{
	size_t	i;

	if (!parr)
		return (0);
	i = 0;
	while (i < na)
	{
		if (parr[i] != p)
			return (0);
		i++;
	}
	return (1);
}

int	ft_psisainparr(t_cvoid **parr, size_t na, t_cvoid **set, size_t ns)
{
	size_t	i;

	if (!parr || !set)
		return (0);
	i = 0;
	while (i < na)
	{
		if (!ft_pisinparr(parr[i], set, ns))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parrdoubles(t_cvoid **parr, size_t na)
{
	size_t	i;

	if (!parr)
		return (0);
	i = 0;
	while (i < na - 1)
	{
		if (ft_pisinparr(parr[i], &parr[i + 1], na - i))
			return (1);
		i++;
	}
	return (0);
}
