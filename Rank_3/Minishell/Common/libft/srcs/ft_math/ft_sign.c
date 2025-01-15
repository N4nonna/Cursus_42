/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:32:24 by mby               #+#    #+#             */
/*   Updated: 2024/03/01 12:26:59 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (0);
	if (n < 0)
		return (-n);
	return (n);
}

t_llint	ft_absll(t_llint n)
{
	if (n == LLONG_MIN)
		return (0);
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_revsign(int *n)
{
	if (*n == INT_MIN)
	{
		*n = 0;
		return (0);
	}
	*n *= -1;
	return (*n);
}

int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	return (1);
}
