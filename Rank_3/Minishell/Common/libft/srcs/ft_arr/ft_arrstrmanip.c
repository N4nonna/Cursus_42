/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrmanip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mby <mby@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:33:22 by mby               #+#    #+#             */
/*   Updated: 2024/05/22 03:06:14 by mby              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_arrstrsize(char **arr)
{
	size_t	ret;

	if (!arr)
		return (0);
	ret = 0;
	while (arr[ret])
		ret++;
	return (ret);
}

char	**ft_arrstriter(char **arr, size_t n, void (*f)(size_t, char**))
{
	size_t	i;

	if (!arr || !f)
		return (NULL);
	i = 0;
	while (i < n)
	{
		f(n, &arr[i]);
		i++;
	}
	return (arr);
}

char	**ft_arrstrrev(char **arr, size_t n)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (i < n / 2)
	{
		ft_switchpoint(&(((void **)arr)[i]), &(((void **)arr)[n - i - 1]));
		i++;
	}
	return (arr);
}
