/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:52:14 by mby               #+#    #+#             */
/*   Updated: 2024/03/04 14:56:35 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_bestestp_twop(void *a, void *b, int (*f)(void *, void *))
{
	if (f(a, b))
		return (b);
	return (a);
}

void	*ft_bestestp_parr(void **arr, size_t n, int (*f)(void *, void *))
{
	size_t	i;
	void	*ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = arr[0];
	while (i != n)
	{
		ret = ft_bestestp_twop(ret, arr[i], f);
		i++;
	}
	return (ret);
}

size_t	ft_bestestp_parr_ind(void **arr, size_t n, int (*f)(void *, void*))
{
	size_t	i;
	void	*bestest;
	size_t	ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = 0;
	bestest = arr[0];
	while (i < n)
	{
		if (!f(bestest, arr[i]))
		{
			bestest = arr[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
