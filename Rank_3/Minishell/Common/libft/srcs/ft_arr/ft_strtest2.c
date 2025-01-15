/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:22:56 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/02/26 12:45:40 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isonef(char *str, int (*f)(int c))
{
	size_t	i;

	if (!str || !f)
		return (0);
	i = 0;
	while (str[i])
	{
		if (f(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isallf(char *str, int (*f)(int c))
{
	size_t	i;

	if (!str || !f)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!(f(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isonefn(char *str, int (*f)(int c), size_t n)
{
	size_t	i;

	if (!str || !f)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		if (f(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isallfn(char *str, int (*f)(int c), size_t n)
{
	size_t	i;

	if (!str || !f)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		if (!(f(str[i])))
			return (0);
		i++;
	}
	return (1);
}
