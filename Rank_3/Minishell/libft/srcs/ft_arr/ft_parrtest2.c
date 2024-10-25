/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrtest2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:22:56 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/10 16:15:52 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_pisoneparrf(void **parr, int (*f)(void *p))
{
	size_t	i;

	if (!parr || !f)
		return (0);
	i = 0;
	while (parr[i])
	{
		if (f(parr[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_pisallparrf(void **parr, int (*f)(void *p))
{
	size_t	i;

	if (!parr || !f)
		return (0);
	i = 0;
	while (parr[i])
	{
		if (!(f(parr[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_pisonefparrn(void **parr, int (*f)(void *p), size_t n)
{
	size_t	i;

	if (!parr || !f)
		return (0);
	i = 0;
	while (i < n && parr[i])
	{
		if (f(parr[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_pisallparrfn(void **parr, int (*f)(void *p), size_t n)
{
	size_t	i;

	if (!parr || !f)
		return (0);
	i = 0;
	while (i < n && parr[i])
	{
		if (!(f(parr[i])))
			return (0);
		i++;
	}
	return (1);
}
