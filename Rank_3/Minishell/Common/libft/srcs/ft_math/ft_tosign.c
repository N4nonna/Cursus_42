/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math07.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:11:20 by mby               #+#    #+#             */
/*   Updated: 2024/03/01 12:25:40 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_tosign(int *n, int s)
{
	if (s == 0 || (*n == INT_MIN && s > 0))
	{
		*n = 0;
		return (0);
	}
	if (s < 0 && *n > 0)
		*n *= -1;
	else if (s > 0 && *n < 0)
		*n *= -1;
	return (*n);
}

t_llint	ft_tosignll(t_llint *n, int s)
{
	if (s == 0 || (*n == LLONG_MIN && s > 0))
	{
		*n = 0;
		return (0);
	}
	if (s < 0 && *n > 0)
		*n *= -1;
	else if (s > 0 && *n < 0)
		*n *= -1;
	return (*n);
}

t_uns	ft_touns(int n)
{
	if (n == INT_MIN)
		return ((t_uns)INT_MAX + 1);
	return ((t_uns)ft_abs(n));
}

t_lluns	ft_tolluns(t_llint n)
{
	if (n == LLONG_MIN)
		return ((t_uns)LLONG_MAX + 1);
	return ((t_uns)ft_absll(n));
}
