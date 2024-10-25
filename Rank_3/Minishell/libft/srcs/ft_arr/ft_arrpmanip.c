/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrpmanip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mby <mby@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:33:22 by mby               #+#    #+#             */
/*   Updated: 2024/05/22 03:04:13 by mby              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	**ft_arrpiter(void **arr, size_t n, void (*f)(size_t, void*))
{
	size_t	i;

	if (!arr || !f)
		return (NULL);
	i = 0;
	while (i < n)
	{
		f(n, arr[i]);
		i++;
	}
	return (arr);
}

void	**ft_arrprev(void **arr, size_t n)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (i < n / 2)
	{
		ft_switchpoint(&(arr)[i], &(arr)[n - i - 1]);
		i++;
	}
	return (arr);
}
