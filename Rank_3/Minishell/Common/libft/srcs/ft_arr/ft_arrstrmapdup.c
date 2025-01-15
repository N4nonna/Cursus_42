/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrmapdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 06:40:30 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/25 12:56:57 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_arrstrdup(char **arr, size_t n)
{
	char	**res;
	size_t	i;

	if (!arr)
		return (NULL);
	res = (char **)ft_calloc(n + 1, sizeof(char *));
	if (res == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = ft_strdup(arr[i]);
		if (!res[i])
			return (ft_freestrarr(res, i), NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_arrstrmap(char **arr, size_t n, void (*f)(size_t, char*))
{
	char	**res;
	size_t	i;

	if (!arr)
		return (NULL);
	res = (char **)ft_calloc(n + 1, sizeof(char *));
	if (res == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = ft_strdup(arr[i]);
		if (!res[i])
			return (ft_freestrarr(res, i), NULL);
		if (!f)
			f(i, res[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
