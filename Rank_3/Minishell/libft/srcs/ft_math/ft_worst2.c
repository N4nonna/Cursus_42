/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_worst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:52:14 by mby               #+#    #+#             */
/*   Updated: 2024/03/04 14:55:22 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_worstestp_parr(void **arr, size_t n, int (*f)(void *, void *))
{
	size_t	i;
	void	*ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = arr[0];
	while (i < n)
	{
		ret = ft_worstestp_twop(ret, arr[i], f);
		i++;
	}
	return (ret);
}

void	*ft_worstestp_twop(void *a, void *b, int (*f)(void *, void *))
{
	if (f(a, b))
		return (a);
	return (b);
}

size_t	ft_worstestp_parr_ind(void **arr, size_t n, int (*f)(void *, void *))
{
	size_t	i;
	void	*worstest;
	size_t	ret;

	if (n == 0)
		return (0);
	i = 0;
	ret = 0;
	worstest = arr[0];
	while (i < n)
	{
		if (f(worstest, arr[i]))
		{
			worstest = arr[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
